#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll convert(string& str){
    for(int i = 0 ; i < (int)str.size() ; i++){
        if(!isdigit(str[i])){
            return 0;
        }
    }
    stringstream ss(str);
    ll re;
    ss >> re;
    return re;
}
void Solve(string& str){
    stringstream ss(str);
    string s;
    ll ans = 0;
    while(ss >> s){
        ans += convert(s);
    }
    cout << ans << endl;
}

int main(){
    string str;
    while(getline(cin, str))
        Solve(str);
    return 0;
}
