#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define MAX 512
ll dp[MAX][MAX];
ll f[MAX];
int Solve(){
    memset(dp, 0, sizeof(dp));
    ll ans = 0, now;
    int n, k, s;
    scanf("%d%d%d", &n, &k, &s);
    for(int i = 1 ; i <= n ; i++)
        dp[k][i] = i != s;
    for(int i = k + 1 ; i < n ; i++){
        now = 0;
        for(int j = 1 ; j <= n ; j++){
            dp[i][j] = 0;
            if( j == s ) continue;
            if( j == s + 1 ){
                if(j > 2)
                    dp[i][j] = dp[i][j-2] + dp[i-1][j-2];
            } else {
                if(j > 1)
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            }
            dp[i][j] %= MOD;
            if(j > s)
                now = (now+dp[i-1][j]) % MOD;
        }
        ans = (ans + (now*f[n-i+k-1]) % MOD) % MOD;
    }
    now = 0;
    for(int i = 1 ; i <= n ; i++){
        if(i == s) continue;
        now = (now+dp[n-1][i]) % MOD;
    }
    ans = ans + ((now*f[k-1])%MOD)%MOD;
    return ans % MOD;
}
int main(){
//    freopen("pd.in", "r", stdin);
    f[0]=1;
    for(int i = 1 ; i < MAX ; i++)
        f[i] = (f[i-1] * i) % MOD;
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++){
        printf("Case #%d: %d\n", i, Solve());
    }
    return 0;
}
