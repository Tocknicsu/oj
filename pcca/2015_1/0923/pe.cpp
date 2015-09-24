#include <bits/stdc++.h>
using namespace std;

void Solve(){
    string str;
    cin >> str;
    int ok = 0;
    for(int i = 1 ; i < (int)str.size() ; i++){
        if(str[i] > str[i-1]){
            if(ok){
                cout << -1 << endl;
                return;
            }
        }
        if(str[i] < str[i-1]){
            ok = true;
        }
    }
}

int main(){
    int n;
    cin >> n;
    while(n--)
        Solve();
    return 0;
}
