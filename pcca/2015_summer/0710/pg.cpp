#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int dp[5002][5002];
int sum[5002];
int n, a, b, k;
int get_sum(int x, int y){
    return (sum[y] - sum[x] + mod) % mod;
}
void calc_sum(int x){
    for(int i = 1 ; i <= n ; i++)
        sum[i] = (dp[x][i] + sum[i-1]) % mod;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> a >> b >> k;
    dp[0][a] = 1;
    calc_sum(0);
    for(int t = 1 ; t <= k ; t++){
        for(int i = 1 ; i <= n ; i++){
            
            if(i == b) continue;
            if(i < b){
                int end = b - (abs(b-i) / 2) - 1;
                dp[t][i] = (get_sum(0, end) - dp[t-1][i] + mod) % mod;
                //cout << i << ' ' << 1 << ' ' << end << endl;
            } else {
                int start = b + (abs(b-i) / 2) + 1;
                dp[t][i] = (get_sum(start - 1, n) - dp[t-1][i] + mod) % mod;
                //cout << i << ' ' << start << ' ' << n << endl;
            }
        }
        calc_sum(t);
    }
    cout << sum[n] << endl;
    return 0;
}
