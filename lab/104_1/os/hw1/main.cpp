#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <csignal>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;

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
    return cmd;
}

void signal_handler(int sig){
    cout << "Catch Signal: " << sig << endl;
    if(sig == SIGINT){
        cout << "XDDD" << endl;
    }
}

int main(){
    cout << "Welcome to mysh by 0316239!" << endl;
    signal(SIGINT, &signal_handler);
    signal(SIGSTOP, &signal_handler);
    string str;
    while(cout << get_username() << ' ' << get_cwd() << endl << "mysh> ", getline(cin, str)){
        vector<string> p_cmd = parse_multi_cmd(str);
        for(int i = 0 ; i < (int)p_cmd.size() ; i++){
            if(p_cmd[i] == "&") continue;
            vector<string> cmd = parse_single_cmd(p_cmd[i]);
            string _exec = cmd[0];
        }
    }
    cout << "Goodbye!" << endl;

    return 0;
}
