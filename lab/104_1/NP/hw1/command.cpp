#include "command.h"
vector<COMMAND> parse(string buf){
    vector<COMMAND> re;
    stringstream ss(buf);
    string str;
    re.push_back(COMMAND());
    while(ss >> str){
        cout << str << endl;
        if(str[0] == '|'){
            if(str.size()==1)
                re.back().second.first = 1;
            else
                re.back().second.first = atoi(str.substr(1, str.size()-1).c_str());
        } else if (str[0] == '!'){
            if(str.size()==1)
                re.back().second.second = 1;
            else
                re.back().second.second = atoi(str.substr(1, str.size()-1).c_str());
        } else {
            if(re.back().second.first != 0 || re.back().second.second != 0)
                re.push_back(COMMAND());
            re.back().first += str + " ";
        }
    }
    return re;
}

void run(string str){
    vector<COMMAND> command = parse(str);
    for(int i = 0 ; i < (int)command.size() ; i++){
        if(fork()){ //parent
        } else {
            if(exec()){
                exit(0);
            }
        }
        cout << command[i].first << "*" << command[i].second.first << "|" << command[i].second.second << endl;
    }
}

#ifdef SINGLE_TEST
int main(){
    string str;
    while(getline(cin, str)){
        run(str);
    }
    return 0;
}
#endif
