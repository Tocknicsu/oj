#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> num;
ll n, l, r, x;
bool judge(int k){
    ll now = 0, u = 0;
    ll _min = 1029384756, _max = -1029384756;
    while(k){
        if(k&1)
            now += num[u], _min = min(_min, num[u]), _max = max(_max, num[u]);
        u++;
        k>>=1;
    }
    return (_max - _min) >= x && ( l <= now && now <= r);
}
int main(){
    cin >> n >> l >> r >> x;
    for(int i = 0, tmp ; i < n ; i++){
        cin >> tmp;
        num.push_back(tmp);
    }
    int ans = 0;
    for(ll i = 0, k = 1 << n ; i < k ; i++){
        ans += judge(i);
    }
    cout << ans << endl;
    return 0;
}
