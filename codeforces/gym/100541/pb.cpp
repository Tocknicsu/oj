#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000
void Solve(ll x){
    ll ans = 0;
    ll di = sqrt(x);
    vector<ll> tmp;
    ll last = x + 1;
    for(ll i = 1 ; i <= di  ; i++){
        ll t = x / i;
        if(t != di)
            ans += t;
        ll nlast = (x/(i+1)) + 1 ;
        ans += (last - nlast) * i;
        last = nlast;
    }
    cout << ans % MOD << endl;
}
int main(){
//    freopen("pb.in", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        ll x;
        cin >> x;
        Solve(x);
    }
    return 0;
}

