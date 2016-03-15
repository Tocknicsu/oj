#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAX = 32768;
vector<ll> prime;
bool p[MAX];
ll pre[MAX], src[MAX], suf[MAX];
ll ppre[MAX], ssuf[MAX];

void build(){
    prime.push_back(2);
    p[0] = p[1] = 1;
    for(ll i = 4 ; i < MAX ; i+=2)
        p[i] = 1;
    for(ll i = 3 ; i * i  < MAX ; i+=2)
        if(!p[i])
            for(ll j = i * i ; j < MAX ; j += 2 * i)
                p[j] = 1;
    for(ll i = 3 ; i < MAX ; i+=2)
        if(!p[i])
            prime.push_back(i);
}


ll lcost(ll a, ll b){
    return ssuf[a] - ssuf[b] - (suf[b+1]) * (b - a);
}
ll rcost(ll a, ll b){
    return ppre[b] - ppre[a] - (pre[a-1]) * (b - a);
}
ll Cost(ll a, ll b){
    ll mid = a + b / 2;
    return lcost(a, mid) + rcost(mid+1, a + b);
}
int main(){
    freopen("pa.in", "r", stdin);
    ll n;
    build();
    while(scanf("%lld", &n), n){
        memset(pre, 0, sizeof(pre));
        memset(suf, 0, sizeof(suf));
        memset(ppre, 0, sizeof(ppre));
        memset(ssuf, 0, sizeof(ssuf));
        memset(src, 0, sizeof(src));
        ll g = 0;
        for(ll i = 1 ; i <= n ; i++)
            scanf("%lld", &src[i]);
        ll ans = 1029384756;
        for(ll i = 1 ; i <= n ; i++)
            pre[i] = pre[i-1] + src[i];
        for(ll i = n ; i > 0 ; i--)
            suf[i] = suf[i+1] + src[i];
        for(ll i = 2 ; i <= n ; i++)
            ppre[i] = ppre[i-1] + pre[i-1];
        for(ll i = n - 1 ; i > 0 ; i--)
            ssuf[i] = ssuf[i+1] + suf[i+1];
        for(ll i = 1 ; i <= n ; i++)
            ans = min(ans, ppre[i] + ssuf[i]);
        for(ll i = 1 ; i <= n ; i++)
            g += i * src[i];
        g /= n;

        for(ll i = 0 ; i < (ll)prime.size() && prime[i] + 1 <= n ; i++){
            ll target = prime[i];
            ll l = max(1ll, g - 2 * target);
            ll r = min(n, g + 3 * target);
            for(ll j = l ; j + target <= r ; j++){
            //for(ll j = 1 ; j + target <= n ; j++){
                ll cost = ppre[j] + ssuf[j+target];
                if(prime[i] == 7){
                    cost += Cost(j, 2) + Cost(j+2, target-4) + Cost(j+target-2, 2);
                } else if(p[prime[i] - 2] == 0) {
                    cost += min(Cost(j, 2)+Cost(j+2,target-2), Cost(j,target-2)+Cost(j+target-2, 2));
                } else {
                    //ll mid = j + target / 2;
                    //cost += lcost(j, mid) + rcost(mid+1, j+target);
                    cost += Cost(j, target);
                }
                ans = min(ans, cost);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
