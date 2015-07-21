#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
int main(){
    ll n, m;
    cin >> n >> m;
    vector<PLL> seg;
    ll L = 1, R = 1;
    for(int i = 1 ; i < n ; i++){
        L = L * 2;
        R = R * 2 + 1;
    }
    R += 1;
    seg.push_back(PLL(L, 1));
    seg.push_back(PLL(R, -1));
    for(int i = 0 ; i < m ; i++){
        ll q, l, r, ans;
        cin >> q >> l >> r >> ans;
        for(int j = q ; j < n ; j++)
            l *= 2, r = 2 * r + 1;
        if(ans){
            seg.push_back(PLL(l, 1));
            seg.push_back(PLL(r+1, -1));
        } else {
            seg.push_back(PLL(L, 1));
            seg.push_back(PLL(l, -1));
            seg.push_back(PLL(r+1, 1));
            seg.push_back(PLL(R, -1));
        }
    }
    sort(seg.begin(), seg.end());
    ll now = 0, ans = 0;
    for(int i = 0 ; i < (int)seg.size() ; i++){
        now += seg[i].second;
        if(i+1 < (int)seg.size() && seg[i+1].second == seg[i].second) continue;
        if(now == m+1){
            if(ans){
                cout << "Data not sufficient!" << endl;
                return 0;
            } else {
                if(seg[i+1].first != seg[i].first+1){
                    cout << "Data not sufficient!" << endl;
                    return 0;
                } else {
                    ans = seg[i].first;
                }
            }
        }
    }
    if(ans)
        cout << ans << endl;
    else
        cout << "Game cheated!" << endl;
    return 0;
}
