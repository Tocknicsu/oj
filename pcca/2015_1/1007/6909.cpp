#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007ll
typedef long long ll;
ll st[512];
ll Solve(){
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    ll t[512][512] = {};
    t[k][0] = 1;
    ll ans = 0;
    if(k+1 == p){
        return st[n-1];
    }
    for(int i = 1 ; i <= n ; i++){
        t[k][i] = i != p;
        if(i > p){
            ans += st[n-2];
            ans %= MOD;
        }
    }
    for(int i = k + 1, d = 2 ; i < n ; i++, d++){
        ll tmp = 0;
        for(int j = i-k+1 ; j <= n ; j++){
            if(j == p) continue;
            if(j == p+1){
                t[i][j] = t[i][j-2] + t[i-1][j-2] % MOD;
            } else {
                t[i][j] = t[i][j-1] + t[i-1][j-1] % MOD;
            }
            if(i != n - 1){
                if(j > p){
                    tmp += t[i][j];
                    tmp %= MOD;
                }
            } else {
                if(j != p){
                    tmp += t[i][j];
                    tmp %= MOD;
                }
            }
        }
        ans += ((tmp * st[(n-d-1)]) % MOD);
        ans %= MOD;
    }
    return ans;
}
int main(){
    st[0] = 1;
    for(int i = 1 ; i <= 500 ; i++)
        st[i] = (st[i-1] * i) % MOD;
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++){
        printf("Case #%d: %lld\n", i, Solve());
    }
}
