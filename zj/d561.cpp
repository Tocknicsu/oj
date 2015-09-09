#include <bits/stdc++.h>
using namespace std;

void Solve(string str){
    bool neg = false;
    if(str[0] == '-'){
        neg = true;
        str = str.substr(1, str.size()-1);
    }
    int p = 0;
    for(int i = 0 ; i < (int)str.size() ; i++)
        if(str[i] == '.') p = i;
    if(p == 0){
        p = str.size();
        str.push_back('.');
    }
    str.push_back('0');
    str.push_back('0');
    str.push_back('0');

    if(str[p+3] >= '5'){
        str[p+3] = '0';
        for(int i = p+2 ; i >= 0 && (str[i+1]=='0' || (i==p-1 && str[i+2]=='0')) ; i--){
            if(i == p) continue;
            if(i==0 && str[i] == '9') cout << 1;
            str[i] = str[i] == '9' ? '0' : str[i]+1;
        }
    }
    if(str[0] == str[2] && str[2] == str[3] && str[0] == '0') neg = false;
    if(neg) cout << '-';
    for(int i = 0 ; i <= p+2 ; i++)
        cout << str[i];
    cout << endl;
}
int main(){
    string str;
    while(cin >> str)
        Solve(str);
    return 0;
}
