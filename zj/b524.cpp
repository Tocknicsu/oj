#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    string str;
    while(getline(cin, str)){
        int ans = 0, time = 0;
        for(int i = 0 ; i < (int)str.size() ; i++){
            if(str[i] == 'y'){
                ans += abs(i - time*3);
                ++time;
            }
        }
        cout << ans << endl;

    }
}
