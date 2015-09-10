#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n, m;
    cin >> n >> m;
    map<ll, bool> k;
    k[0] = 0;
    k[n] = 0;
    for(int i = 0 ; i < m ; i++){
        ll a, b;
        cin >> a >> b;
        k[a-1] ^= 1;
        k[b] ^= 1;
    }
    ll ans = 0;
    bool go = true;
    for(auto a = ++k.begin(), b = k.begin() ; a != k.end() ; ++a, ++b){
        if((*b).s)
            go ^= 1;
        if(go)
            ans += (*a).f - (*b).f;
    }
    cout << ans << endl;
    return 0;
}
