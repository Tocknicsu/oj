#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <csignal>
#include <sys/wait.h>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <map>
#include <list>
using namespace std;

int DEBUG;

int front_pid;
list<int> process;
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
string set_color(string front_color, string backend_color="", string str="", bool reset = 1){
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
    if(front_color.size())
        ss << "\033[" << color[front_color] << "m";
    if(backend_color.size())
        ss << "\033[" << color[backend_color] << "m";
    ss << str;
    if(reset)
        ss << "\033[0m";
    getline(ss, str);
    return str;
}

void set_front_pid(int pid){
    front_pid = pid;
    cout << set_color("blue", "", "", 0) << "Command executed by pid=" << pid << set_color("", "", "", 1) << endl;
}
vector<string> parse_multi_cmd(string str){
    vector<string> cmd;
    cmd.push_back("");
    for(int i = 0 ; i < (int)str.size() ; i++){
        if (str[i] == '|') {
            cmd.push_back("");
        } else if(str[i] == '&') {
            cmd.push_back("&");
        } else {
            cmd.back().push_back(str[i]);
        }
    }
    return cmd;
}
vector<string> parse_single_cmd(string str){
    vector<string> cmd;
    cmd.push_back("");
    for(int i = 0 ; i < (int)str.size() ; i++){
        if(str[i] == ' '){
            if(cmd.back().size())
                cmd.push_back("");
        } else {
            cmd.back().push_back(str[i]);
        }
    }
    while(cmd.size() && !cmd.back().size())
        cmd.pop_back();
    return cmd;
}

void signal_handler(int sig){
    cout << "Catch Signal: " << sig << " front_pid: " << front_pid << endl;
    if(sig == 2){
        if(front_pid){
            kill(front_pid, SIGINT);
            process.push_back(front_pid);
            front_pid = 0;
        }
    } else if(sig == 20){
        if(front_pid){
            cout << "here" << endl;
            kill(front_pid, SIGSTOP);
            cout << "there" << endl;
            DEBUG = 1;
            process.push_back(front_pid);
        }
    }
}

int single_command(string str, bool front = true){
    vector<string> cmd = parse_single_cmd(str);
    if(cmd.size()){
        if(cmd[0] == string("cd")){
            if(cmd.size() > 1){
                if(chdir(cmd[1].c_str()))
                    cout << "No Directory: " << cmd[1] << endl;
            } else {
                chdir(getenv("HOME"));
            }
        } else if (cmd[0] == string("exit")){
            return -1;
        } else {
            int pid = fork();
            if(pid){
                if(front)
                    set_front_pid(pid);
            } else {
                char **args;
                args = new char*[cmd.size()+1];
                for(int i = 0 ; i < (int)cmd.size() ; i++){
                    args[i] = new char[cmd[i].size()+1];
                    strcpy(args[i], cmd[i].c_str());
                }
                args[cmd.size()] = 0;
                if(execvp(cmd[0].c_str(), args)){
                    cout << "Command not found: " << cmd[0] << endl;
                }
                for(int i = 0 ; i < (int)cmd.size() ; i++)
                    delete [] args[i];
                delete [] args;
                exit(1);
            }
        }
    }
    return 0;
}
void multi_command(vector<string> cmds){
    int pid = fork();
    if(cmds.back() == "&") cmds.pop_back();
    if(pid){
        set_front_pid(pid);
    } else {
        for(int i = 0 ; i < (int)cmds.size() ; i++)
            single_command(cmds[i], false);
        exit(0);
    }
}
void kill_zombie(){
    for(list<int>::iterator it = process.begin() ; it != process.end() ; ++it){
        int pid = *it;
        int status;
        waitpid(front_pid, &status, WNOHANG);
        if(WIFEXITED(status)){
            list<int>::iterator tmp = it;
            ++it;
            process.erase(tmp);
            waitpid(pid, &status, 0);
        }
    }
}

int main(){
    cout << "Welcome to mysh by 0316239!" << endl;
    signal(SIGINT, &signal_handler);
    signal(SIGTSTP, &signal_handler);
    string str;
    while(
            cout 
                << "[" << set_color("azure", "", get_username(), 1) << "]" 
                << " - [" << set_color("yellow", "", get_cwd(), 1) << "]" << endl 
                << set_color("red", "", "mysh> ", 1),
             getline(cin, str)){
        kill_zombie();
        front_pid = 0;
        vector<string> p_cmd = parse_multi_cmd(str);
        if(p_cmd.size() == 1){
            if(single_command(p_cmd[0]))
                break;
        } else {
            multi_command(p_cmd);
        }
        if(p_cmd.size() >= 1 && p_cmd.back() == "&"){
            process.push_back(front_pid);
        } else {
            while(front_pid){
                int status;
                waitpid(front_pid, &status, WNOHANG);
                if(DEBUG){
                    cout << status << endl;
                    sleep(1);
                }
                if(WIFEXITED(status)){
                    front_pid = 0;
                    waitpid(front_pid, &status, 0);
                } else if(WIFSTOPPED(status)){
                    front_pid = 0;
                }
            }
        }
    }
    cout << "Goodbye!" << endl;
    return 0;
}
