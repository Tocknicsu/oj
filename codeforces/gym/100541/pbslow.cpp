#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000
inline ll find(ll x, ll t){
    ll now = t;
    ll re = x / t;
    ll step = x / re;
    while(step && now < x){
        if(re == x / (now+step)){
            now += step;
        } else {
            step >>= 1;
        }
    }
    return now;
}
void Solve(ll x){
    ll ans = 0;
    ll di = min(ll(sqrt(x)) * 5ll, ll(MOD*10));
    for(ll i = 1 ; i < di  ; i++)
        ans += x / i;
    for(ll i = di ; i <= x ; i++){
        ll t = find(x, i);
        ll add = (t - i + 1) * ( x / i);
        ans += add;
        i = t;
    }
    cout << ans % MOD << endl;
}
int main(){
//    freopen("pb.in", "r", stdin);
    for(ll x = 0 ; x < 30 ; ++x){
        Solve(x+1000000000000ll);
    }
    return 0;
    int t;
    cin >> t;
    while(t--){
        ll x;
        cin >> x;
        Solve(x);
    }
    return 0;
}
