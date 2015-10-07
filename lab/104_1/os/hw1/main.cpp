#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
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
void parse_cmd(string str){
}

int main(){
    cout << "Welcome to mysh by 0316239!" << endl;
    while(1){
        string cmd;
        cout << get_username() << ' ' << get_cwd() << endl;
        printf("mysh> ");
        getline(cin, cmd);
        parse_cmd(cmd);
    }

    return 0;
}
