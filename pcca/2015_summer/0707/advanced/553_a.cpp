#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll fact[1024], rfact[1024];
ll rev(ll x){
    ll re = 1, t = 1000000005;
    while(t){
        if(t&1)
            re = (re * x) % MOD;
        x = x * x % MOD;
        t >>= 1;
    }
    return re;
}
void build(){
    fact[0] = rfact[0] = 1;
    for(int i = 1 ; i < 1024 ; i++){
        fact[i] = fact[i-1] * i % MOD;
        rfact[i] = rev(fact[i]);
    }
}
ll C(ll n, ll m){
    return ((fact[n] * rfact[m])%MOD * rfact[n-m])%MOD;
}
int main(){
    build();
    ll n, now = 0, tmp, ans = 1;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> tmp;
        ans = (ans * C(now+tmp-1, now))%MOD;
        now += tmp;
    }
    cout << ans << endl;
    return 0;
}
