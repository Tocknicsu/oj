#include <bits/stdc++.h>
using namespace std;

bool Solve(){
    string str;
    cin >> str;
    if((str.size() & 1) == 0) return true;
    bool flag = false;
    for(int i = 1 ; i < (int)str.size() ; i++)
        flag |= str[i] == str[i-1];
    if(!flag) return false;
    if(str.size()%4 != 3) return true;
    for(int i = 0 ; i < (int)str.size() / 2 ; i++)
        if(str[i] != str[str.size()-1-i]) return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    while(n--)
        cout << (Solve()? "LIVES" : "DIES") << endl;
    return 0;
}
