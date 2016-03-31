#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct S{
    ll l, r, t;
    S(){}
    S(ll _l, ll _r, ll _t) : l(_l), r(_r), t(_t){}
    bool operator<(const S &b) const {
        return r < b.r;
    }
};
ll n, r, v1, v2, v3;
map<vector<ll>, ll> record;
vector<S> s;
ll dfs(ll range_t1, ll range_t2, ll id){
    if(record[{range_t1, range_t2, id}])
        return record[{range_t1, range_t2, id}];
    if(id == (int)s.size())
        return 0;
    if(s[id].t == 1){
        if(range_t1 >= s[id].l)
            return record[{range_t1, range_t2, id}] = dfs(range_t1, range_t2, id+1);
        else
            return record[{range_t1, range_t2, id}] = min(
                    dfs(s[id].r + 2*r, range_t2, id+1)+v1,
                    dfs(s[id].r + 2*r, s[id].r + 2*r, id+1)+v3);
    } else {
        if(range_t2 >= s[id].l)
            return record[{range_t1, range_t2, id}] = dfs(range_t1, range_t2, id+1);
        else
            return record[{range_t1, range_t2, id}] = min(
                    dfs(range_t1, s[id].r + 2*r, id+1) + v2,
                    dfs(s[id].r + 2*r, s[id].r + 2*r, id+1) + v3);
    }
}
int main(){
    //freopen("pe.in", "r", stdin);
    while(scanf("%lld%lld%lld%lld%lld", &n, &r, &v1, &v2, &v3), n || r || v1 || v2 || v3){
        s.clear();
        record.clear();
        ll x, y, z;
        for(int i = 0 ; i < n ; i++){
            scanf("%lld%lld%lld", &x, &y, &z);
            s.push_back(S(x, y, z));
        }
        sort(s.begin(), s.end());
        printf("%lld\n", dfs(-1, -1, 0));
    }
    return 0;
}
