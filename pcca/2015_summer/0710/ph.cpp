#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define INF 1000000000000000ll
typedef long long ll;
typedef pair<ll, ll> PII;
typedef pair<PII, ll> PPI;
vector<PII> land;
vector<PPI> gap;    // min max id
set<PII> bri;    // len id
map<ll, ll> ans;  // gap_id, bri_id
bool cmp(const PPI &a, const PPI &b){
    if(a.f.s == b.f.s)
        return a.f.f < b.f.f;
    return a.f.s < b.f.s;
}
void end(){
    cout << "No" << endl;
    exit(0);
}
int main(){
    ll n, m, tmp;
    cin >> n >> m;
    // land in
    for(ll i = 0 ; i < n ; i++){
        ll l, r;
        cin >> l >> r;
        land.push_back(PII(l, r));
    }
    // gap build
    for(ll i = 1 ; i < n ; i++){
        gap.push_back(PPI(PII(land[i].f-land[i-1].s, land[i].s-land[i-1].f), i));
    }
    // bri in
    for(ll i = 0 ; i < m ; i++){
        cin >> tmp;
        bri.insert(PII(tmp, i));
    }
    sort(gap.begin(), gap.end(), cmp);
    for(int i = 0 ; i < (int)gap.size() ; i++){
        if(bri.empty())
            end();
        set<PII>::iterator it = bri.lower_bound(PII(gap[i].f.f, -INF));
        if(it == bri.end() || it->f > gap[i].f.s)
            end();
        ans[gap[i].s - 1] = it->s + 1;
        bri.erase(it);
    }
    cout << "Yes" << endl;
    for(ll i = 0 ; i < (ll)gap.size() ; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
