#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<ll, ll> pll;
bool cmp(const pll a, const pll &b){
    return a.s == b.s ? a.f < b.f : a.s > b.s;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<pll> vec(n);
    for(int i = 0 ; i < n ; i++)
        cin >> vec[i].f >> vec[i].s;
    sort(vec.begin(), vec.end(), cmp);
    ll ans = 0;
    for(int i = 0 ; i < (int)vec.size() ; i++){
        if(vec[i].f){
            ans += vec[i].f + vec[i].s * ans;
            ans %= 100000007;
            
        }
    }
    cout << ans << endl;
    return 0;
}
