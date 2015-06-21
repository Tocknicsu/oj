#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
ll inver(ll x){
    ll t = MOD - 2, now = 1, tmp = x;

    while(t){
        if(t&1)
            now = (now * tmp) % MOD;
        tmp = (tmp * tmp) % MOD;
        t>>=1;
    }
    return now;
}
void Solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> vec1, vec2;
    vec1.push_back(1), vec2.push_back(1);
//    vecotr<ll> vec3;
    for(int i = 0 ; i < n/2 ; i++){
        ll x;
        cin >> x;
        int sz = vec1.size();
        for(int j = 0 ; j < sz ; j++)
            vec1.push_back((vec1[j]*x)%MOD);
    }
    for(int i = n/2 ; i < n ; i++){
        ll x;
        cin >> x;
        int sz = vec2.size();
        for(int j = 0 ; j < sz ; j++)
            vec2.push_back((vec2[j]*x)%MOD);
    }
//    cout << vec1.size() << " " << vec2.size() << endl;
///    for(auto x : vec1)
    map<ll, ll> a, b;
    for(int i = 0 ; i < (int)vec1.size() ; i++)
        a[vec1[i]]++;
    for(int i = 0 ; i < (int)vec2.size() ; i++)
        b[vec2[i]]++;
    a[1]--;
    b[1]--;
    int ans = 0;
    if(m != 0){
        ans = a[m]+b[m];
        for(map<ll, ll>::iterator x = a.begin() ; x != a.end() ; ++x)
//        for(auto x : a){
            ans += (x->second * b[(m*inver(x->first))%MOD]);
    } else {
        ans += a[0] * vec2.size() + b[0] * vec1.size() - a[0] * b[0];
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while(n--)
        Solve();
    return 0;
}
