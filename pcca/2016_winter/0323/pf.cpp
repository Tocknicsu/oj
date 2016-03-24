#include <bits/stdc++.h>
using namespace std;

int main(){
//    freopen("pf.in", "r", stdin);
    ios_base::sync_with_stdio(0), cin.tie(0);
    string str;
    int now = 0;
    while(cin >> str){
        if(str == "$$$" || str == "###"){
            printf("%d:%02d\n", now/60, now%60);
            now = 0;
            if(str == "$$$")
                continue;
            else
                return 0;
        }
        int flag = str[0] == '+' ? 1 : -1;
        str = str.substr(1, str.size()-1);
        if(!isdigit(str[0])){
            str = string("0") + str;
        }
        if(!isdigit(str.back()))
            str = str + string("0");
        for(int i = 0 ; i < (int)str.size() ; i++)
            str[i] = str[i] == '.' ? ':' : str[i];
        int a, b;
        sscanf(str.c_str(), "%d:%d", &a, &b);
        now += (a * 60 + b) * flag;
    }

    return 0;
}
