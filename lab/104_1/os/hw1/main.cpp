#include <bits/stdc++.h>
#include <termios.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
using namespace std;

map<int, int> process;
set<int> all_process;
int last_status;

string get_username(){
    char buffer[1024];
    getlogin_r(buffer, 1024);
    return string(buffer);
}
string get_cwd(){
    char buffer[1024];
    getcwd(buffer, 1024);
    return string(buffer);
}
string set_color(string front_color, string backend_color="", string str="", bool reset = 1, bool hight_light=0){
    map<string, int> color;
    color["black"]  = 30;
    color["red"]    = 31;
    color["green"]  = 32;
    color["yellow"] = 33;
    color["blue"]   = 34;
    color["purple"] = 35;
    color["azure"]  = 36;
    color["white"]  = 37;
    stringstream ss;
    if(front_color.size()) ss << "\033[" << color[front_color] << "m";
    if(backend_color.size()) ss << "\033[" << color[backend_color] << "m";
    if(hight_light) ss << "\033[1m";
    ss << str;
    if(reset) ss << "\033[0m";
    getline(ss, str);
    return str;
}
void prompt(){
    time_t rawtime;
    struct tm * timeinfo;
    char time_buffer [80];
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (time_buffer,80,"%Y-%m-%d %H-%M-%S",timeinfo);
    cout 
        << "┌─[" << set_color("azure", "", get_username(), 1, 1) << "]" << 
        " - [" << set_color("yellow", "", get_cwd(), 1, 1) << "]" << 
        " - [" << set_color("yellow", "", time_buffer, 1, 1) << "]" << endl
        << "├─[" << last_status << "] "
        << set_color("red", "", "➤  ", 1) << flush;
}
vector<string> parse_multi_cmd(string source){
    char str[source.size()+1];
    strcpy(str, source.c_str());
    vector<string> cmd;
    char *ptr = strtok(str, "|");
    while(ptr){
        cmd.push_back(ptr);
        ptr = strtok(NULL, "|");
    }
    if(cmd.size() && cmd.back().size() && cmd.back().back() == ' ') cmd.back().pop_back();
    if(cmd.size() && cmd[0].empty()) cmd.pop_back();
    if(cmd.size() && cmd.back().size() && cmd.back().back() == '&'){
        cmd.back().pop_back();
        cmd.push_back("&");
    }
    
    return cmd;
}
vector<string> parse_single_cmd(string str){
    vector<string> cmd;
    stringstream ss(str);
    string tmp;
    while(ss >> tmp)
        cmd.push_back(tmp);
    return cmd;
}
void signal_handler_SIGINT(int sig){
    last_status = 1;
    cout << endl;
    prompt();
}
void WAIT(int pid){
    int status;
    for(int i = 0 ; i < process[pid] ; i++){
        int m_pid = waitpid(-pid, &status, WUNTRACED);
        if(m_pid == -1) continue;
        if(WIFEXITED(status) || WIFSIGNALED(status)){
            all_process.erase(m_pid);
        }
    }
    last_status = WEXITSTATUS(status);
}
void signal_handler_SIGTSTP(int sig){
    cout << endl;
    prompt();
}
void signal_handler_SIGCHLD(int sig){
    int pid, status;
    while(pid = waitpid(-1, &status, WNOHANG), pid > 0){
    }
}
void my_exit(){
    cout << "Goodbye!" << endl;
    exit(0);
}
bool internal(string str){
    vector<string> cmd = parse_single_cmd(str);
    if(cmd[0] == string("cd")){
        if(cmd.size() > 1){
            if(chdir(cmd[1].c_str()))
                cout << "No Directory: " << cmd[1] << endl;
        } else {
            chdir(getenv("HOME"));
        }
    } else if (cmd[0] == string("exit")){
        my_exit();
    } else if (cmd[0] == string("fg")){
        int pid = atoi(cmd[1].c_str());
        kill(-pid, SIGCONT);
        tcsetpgrp(STDIN_FILENO, pid);
        WAIT(pid);
        tcsetpgrp(STDIN_FILENO, getpid());
    } else if (cmd[0] == string("bg")){
        kill(-atoi(cmd[1].c_str()), SIGCONT);
    } else if (cmd[0] == string("kill")){
        kill(atoi(cmd[1].c_str()), SIGINT);
    } else {
        return false;
    }
    return true;
}
int external(string str){
    vector<string> cmd = parse_single_cmd(str);
    char **args;
    args = new char*[cmd.size()+1];
    for(int i = 0 ; i < (int)cmd.size() ; i++){
        args[i] = new char[cmd[i].size()+1];
        strcpy(args[i], cmd[i].c_str());
    }
    args[cmd.size()] = 0;
    if(execvp(cmd[0].c_str(), args)){
        cerr << "Command not found: " << cmd[0] << endl;
    }
    for(int i = 0 ; i < (int)cmd.size() ; i++)
        delete [] args[i];
    delete [] args;
    exit(1);
}
bool my_getline(string &str){
    return (bool)getline(cin, str);
}
void do_command(string str){
    vector<string> p_cmd = parse_multi_cmd(str);
    bool background = false;
    if(p_cmd.size() && p_cmd.back() == "&"){
        p_cmd.pop_back();
        background = true;
    }
    if(p_cmd.size() == 0) return;
    if(p_cmd.size() > 1 || (!internal(p_cmd[0]))){
        int first_pid = 0;
        int pip_num = p_cmd.size() - 1;
        int pip[pip_num][2];
        for(int i = 0 ; i < (int)p_cmd.size() ; i++){
            if(i != pip_num){
                pipe(pip[i]);
            }
            int pid = fork();
            if(pid){
                int x = setpgid(pid, first_pid);
                if(x == -1)
                    perror("");
                all_process.insert(pid);
                if(!first_pid){
                    first_pid = pid;
                    tcsetpgrp(STDIN_FILENO, first_pid);
                } else {
                    close(pip[i-1][0]), close(pip[i-1][1]);
                }
            } else {
                if(i == 0)
                    raise(SIGSTOP);
                if(i != pip_num){
                    dup2(pip[i][1], 1);
                    close(pip[i][0]);
                    close(pip[i][1]);
                }
                if(i != 0){
                    dup2(pip[i-1][0], 0);
                    close(pip[i-1][0]);
                    close(pip[i-1][1]);
                }
                external(p_cmd[i]);
            }
            /* for beauty */
            cout << (i != (int)p_cmd.size()-1 ? "├─" : "└─");
            cout << set_color("azure", "", "", 0, 1) << "[" << pid << "] - [" << getpgid(pid) << "] ";
            vector<string> cmds = parse_single_cmd(p_cmd[i]);
            for(int j = 0 ; j < (int)cmds.size() ; j++)
                cout << cmds[j] << ' ';
            cout << set_color("", "", "", 1) << endl;
            /* for beauty */
        }
        kill(first_pid, SIGCONT);
        process[first_pid] = p_cmd.size();
        if(!background){
            WAIT(first_pid);
        }
        tcsetpgrp(STDIN_FILENO, getpid());
    }
}
int main(){
    cout << "Welcome to mysh by 0316239!" << endl;
    signal(SIGINT, &signal_handler_SIGINT);
    signal(SIGTSTP, &signal_handler_SIGTSTP);
    signal(SIGCHLD, &signal_handler_SIGCHLD);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    string str;
    while(prompt(), my_getline(str)){
        last_status = 0;
        do_command(str);
    }
    return 0;
}
