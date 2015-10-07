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
vector<string> parse_cmd(string str){
    cout << "===== cmd parse start =====" << endl;
    cout << "command: " << str << endl;
    cout << "===== cmd parse end =====" << endl;
    vector<string> cmd;
    return cmd;
}

int main(){
    cout << "Welcome to mysh by 0316239!" << endl;
    while(1){
        cout << get_username() << ' ' << get_cwd() << endl;
        cout << "mysh> ";

        string str;
        getline(cin, str);
        system(str.c_str())
        //vector<string> p_cmd = parse_cmd(str);
    }

    return 0;
}
