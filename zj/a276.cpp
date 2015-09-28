#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    while(~scanf("%d", &n)){
        vector<ll> v(n);
        for(ll i = 0 ; i < n ; i++)
            scanf("%lld", &v[i]);
        ll x = std::accumulate(v.begin(), v.end(), 0);
        ll ans = 2147483647;
        for(ll i = (1 << n) - 1 ; i >= 0 ; i--){
            ll tmp = 0;
            for(ll j = 0 ; j < n ; j++){
                if(i&(1<<j))
                    tmp += v[j];
            }
            ans = min(ans, abs(x - 2*tmp));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
