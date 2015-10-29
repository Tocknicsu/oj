#include <bits/stdc++.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
#include <termios.h>
#include <errno.h>
using namespace std;
#define BUFFER_SIZE 1024
#define WHITESPACE " \n\r\t\a\b\x0A"
typedef vector<string> CMD;
/* color definition */
#define NONE "\033[m"
#define RED "\033[0;32;31m"
#define GREEN "\033[0;32;32m"
#define BLUE "\033[0;32;34m"
#define PURPLE "\033[0;35m"
#define BROWN "\033[0;33m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[1;37m"
#define CYAN "\033[1;36m" 
int mysh_pid, mysh_pgid;
set<int> bg_pid;
map<int, int> pipe_command_count;
int last_status = 0;
inline void my_printf(const char* color, const char *format, ...){
    va_list args;
    va_start(args, format);
    char buf[2048] = {0};
    strcat(buf, color);
    strcat(buf, format);
    strcat(buf, NONE);
    vfprintf(stdout, buf, args);
    va_end(args);
    fflush(stdout);
}
inline void welcome(){
    my_printf(WHITE, "[%d] - Welcome to mysh by 0316320!\n", mysh_pid);
}
inline int prompt(){
    char cwd[BUFFER_SIZE], user[BUFFER_SIZE], hostname[BUFFER_SIZE];
    time_t t = time(NULL);
    tm datetime = *localtime(&t);
    getlogin_r(user, BUFFER_SIZE);
    getcwd(cwd, BUFFER_SIZE);
    gethostname(hostname, BUFFER_SIZE);
    my_printf(CYAN, "[%s", user);
    my_printf(NONE, "@");
    my_printf(CYAN, "%s]", hostname);
    my_printf(NONE, " - ");
    my_printf(YELLOW, "[%s]", cwd);
    my_printf(NONE, " - ");
    my_printf(BROWN, "[%d-%02d-%02d %02d:%02d:%02d]", datetime.tm_year+1900, datetime.tm_mon+1, datetime.tm_mday, datetime.tm_hour, datetime.tm_min, datetime.tm_sec);
    my_printf(NONE, "\n");
    my_printf(WHITE, "[%d] ", last_status);
    my_printf(PURPLE, "mysh> ");
    return 1;
}
inline CMD _parse_command(const string& command){
    CMD res;
    stringstream ss;
    ss << command;
    string cmd;
    while(ss>>cmd)res.push_back(cmd);
    return res;
}
inline pair<vector<CMD>, int> parse_command(char *command){
    vector<CMD> res;
    bool background = false;
    int len = strlen(command);
    while(len&&isspace(command[len-1]))command[--len] = 0;
    if(len&&command[len-1]=='&'){
        background = true;
        command[--len] = 0;
    }
    char *ptr = strtok(command, "|");
    while(ptr){
        res.push_back(_parse_command(ptr));
        ptr = strtok(NULL, "|");
    }
    return make_pair(res, background);
}
inline int change_dir(const CMD& command){
    if(chdir(command.size()==1?getenv("HOME"):command[1].c_str()) == -1)
		my_printf(NONE, "cd: no such file or directory: %s\n", command.size()==1?getenv("HOME"):command[1].c_str() );
	return errno;
}
inline void my_wait(int pid, int *status, int option){
    int t_status, pipe_num = pipe_command_count[pid];
    if(!pipe_command_count[pid])waitpid(pid, &t_status, option);
    else for(int i=0;i<pipe_num;i++){
        waitpid(-pid, &t_status, option);
        if(WIFEXITED(t_status))pipe_command_count[pid]--;
    }
    if(WIFEXITED(t_status))last_status = WEXITSTATUS(t_status);
    if(status)*status = t_status;
}
inline int my_fg(int pid){
    if(kill(-pid, SIGCONT)==-1)return errno;
    tcsetpgrp(0, pid);
    bg_pid.erase(pid);
    my_wait(pid, NULL, WUNTRACED);
    tcsetpgrp(0, getpgrp());
    return 0;
}
inline int my_bg(int pid){
    if(kill(-pid, SIGCONT)==-1)return errno;
    bg_pid.insert(pid);
    return 0;
}
inline int my_kill(int pid){
    bg_pid.erase(pid);
    return kill(-pid, SIGINT);
}
inline void my_exit(int status){
    for(auto pid: bg_pid)
        my_kill(pid), my_wait(pid, NULL, 0);
    my_printf(RED, "Goodbye\n");
    exit(status);
}
inline int my_exec(const CMD& command){
    const char *args[BUFFER_SIZE]={0};
    for(int i=0;i<(int)command.size();i++)
        args[i] = command[i].c_str();
    if(execvp(args[0], (char *const*)args) == -1){
        my_printf(NONE, "-mysh: %s: command not found\n", args[0]);
        exit(errno);
    }
    return 0;
}
inline void my_command_info(const CMD& command, int background=0){
    my_printf(GREEN, "[%d] - [%d] %s %s\n", getpid(), getpgrp(), command[0].c_str(), background?"[background]":"");
}
inline int do_multi_command(const vector<CMD>& command, int background=0){
    int p[command.size()][2];
    int pgid = 0, pid;
    vector<int> p_pid;
    for(int i=0;i<(int)command.size();i++){
		pipe(p[i]);
        p_pid.push_back(pid=fork());
        if(pid==0){
            if(i==0&&!background)tcsetpgrp(0, getpid());
            my_command_info(command[i], background);
            if(i!=0){
				dup2(p[i-1][0], 0);
				close(p[i-1][0]);
				close(p[i-1][1]);
			}
            if(i!=(int)command.size()-1){
				dup2(p[i][1], 1);
				close(p[i][0]);
				close(p[i][1]);
			}
            my_exec(command[i]);
        }else if(pid>0){
            setpgid(pid, pgid);
			if(i!=0) close(p[i-1][0]), close(p[i-1][1]);
            if(i==0)pipe_command_count[pgid=pid]=command.size();
        }else{
            my_printf(RED, "fork error\n");
            return errno;
        }
    }
    if(!background){
        my_wait(pgid, NULL, WUNTRACED);
        tcsetpgrp(0, mysh_pgid);
    }else{
        bg_pid.insert(pgid);
    }
    return 0;
}
inline int do_command(const vector<CMD>& command, int background=0){
    if(command.size()==0)return 2;
    /* internal command */
    if(command[0][0] == "exit"){
        my_exit(0);
    }else if(command[0][0] == "cd"){
        return change_dir(command[0]);
    }else if(command[0][0] == "fg"){
        if(command[0].size()<2)return 2;
        return my_fg(stoi(command[0][1]));
    }else if(command[0][0] == "bg"){
        if(command[0].size()<2)return 2;
        return my_bg(stoi(command[0][1]));
    }else if(command[0][0] == "kill"){
        if(command[0].size()<2)return 2;
        return my_kill(stoi(command[0][1]));
    }
	return do_multi_command(command, background);
}
void zombie_handler(int sig){
    int status, pid = waitpid(-1, &status, WNOHANG);
    if(pid!=-1&&WIFEXITED(status)){
        if(bg_pid.find(pid)!=bg_pid.end())my_printf(RED, "pid=%d exit with %d\n", pid, WEXITSTATUS(status));
        else last_status = WEXITSTATUS(status);
        bg_pid.erase(pid);
    }
}
void sigint_handler(int sig){
    if(tcgetpgrp(0)==mysh_pgid){
        fflush(stdin);
        my_printf(NONE, "\n");
        prompt();
    }
}
void sigtstp_handler(int sig){}
int main(){
    mysh_pgid = getpgid(mysh_pid=getpid());
    signal(SIGCHLD, zombie_handler);
    signal(SIGINT, sigint_handler);
    signal(SIGTSTP, sigtstp_handler);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    char command[BUFFER_SIZE];
    welcome();
    while(prompt()){
        if(fgets(command, BUFFER_SIZE, stdin)==NULL)my_exit(0);
        command[strlen(command)-1] = 0;
        auto res = parse_command(command);
        int _last_status = do_command(res.first, res.second);
        last_status = _last_status?_last_status:last_status;
    }
    return 0;
}
