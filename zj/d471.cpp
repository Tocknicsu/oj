#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        string ans;
        for(int i = 0 ; i < n ; i++)
            ans.push_back('0');
        int x = pow(2, n);
        for(int i = 0 ; i < x ; i++){
            cout << ans << endl;
            ans[n-1] = ans[n-1] == '0' ? '1' : '0';
            for(int j = n - 2 ; j>=0 && ans[j+1]=='0' ; j--){
                ans[j] = ans[j] == '0' ? '1' : '0';
            }
        }
    }
    return 0;
}
