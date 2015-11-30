#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<ll, ll> PII;
ll dp[128][65536];
int main(){
 //   freopen("pd.in", "r", stdin);
    int n, k, s;
    while(scanf("%d", &n), n){
        scanf("%d%d", &k, &s);
        int tmp;
        memset(dp, 0, sizeof(dp));
        for(int i = 0 ; i < 65536 ; i++)
            dp[0][i] = 0;
        for(int i = 1 ; i <= n ; i++){
            queue<PII> Q;
            scanf("%d", &tmp);
            for(int j = 0 ; j <= k ; j++){
                while( Q.size() && ((j - Q.front().f > s) || dp[i-1][j] < Q.front().s ))
                    Q.pop();
                if( (Q.size() && Q.back().s <= dp[i-1][j]) || Q.empty() ){
                    Q.push(PII(j, dp[i-1][j]));
                }
                dp[i][j] = Q.front().s + (j - tmp) * (j - tmp);
            }
        }
        ll ans = dp[n][0];
        for(int i = 0 ; i <= k ; i++)
            ans = min(dp[n][i], ans);
        printf("%lld\n", ans);

    }
    
    return 0;
}
