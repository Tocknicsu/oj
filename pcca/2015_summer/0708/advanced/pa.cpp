#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, a, b, num[256];
    while(cin >> n >> a >> b, n || a || b){
        int ans = 0, Max = 0;
        for(int i = 1 ; i <= n ; i++)
            cin >> num[i];
        
        for(int i = a ; i <= b ; i++){
            if(Max <= num[i] - num[i+1]){
                ans = i;
                Max = num[i] - num[i+1];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
