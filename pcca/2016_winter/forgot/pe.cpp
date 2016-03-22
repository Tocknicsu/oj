#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<ll, ll> PII;
ll ans[64];
PII vote[64];
ll dp[64];

int main(){
    freopen("pe.in", "r", stdin);
    int n, m, t = 1;
    while(scanf("%d%d", &n, &m), n || m){
        for(int i = 0 ; i < n ; i++){
            scanf("%lld%lld", &vote[i].f, &vote[i].s);
            //scanf("%I64d%I64d", &vote[i].f, &vote[i].s);
        }
        memset(ans, 0, sizeof(ans));
        for(int i = 0 ; i < n ; i++){
            vote[i].s--;
            memset(dp, 0, sizeof(dp));
            dp[0] = 1;
            for(int r = 0 ; r < n ; r++){
                for(int j = 0 ; j < vote[r].s ; j++){
                    for(int k = m ; k >= vote[r].f ; k--)
                        dp[k] += dp[k-vote[r].f];
                }
            }
            for(int j = max(m - vote[i].f, 0ll) ; j < m ; j++)
                ans[i] += dp[j];
            vote[i].s++;
        }

        printf("Case %d:", t++);
        for(int i = 0 ; i < n ; i++)
            //printf(" %I64d", ans[i]);
            printf(" %lld", ans[i]);
        printf("\n");
    }
    return 0;
}
