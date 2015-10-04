#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve(){
    int n, d, k;
    scanf("%d%d%d", &n, &d, &k);
    vector<ll> dp[2];
    dp[0] = dp[1] = vector<ll>(n+1);
    dp[0][0] = dp[1][0] = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = max(i - k, 0) ; j <= i - 1 ; j++)
            dp[0][i] += dp[1][j];
        for(int j = max(i - k - 1, 0) ; j <= max(i - d - 1, 0) ; j++)
            dp[1][i] += dp[1][j];
    }
    printf("%lld\n", dp[0][n]+dp[1][n]);
    
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
