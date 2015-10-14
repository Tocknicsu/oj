#include <bits/stdc++.h>
using namespace std;
#define ALL(v) v.begin(), v.end()
struct S{
    int t, x, sy, ey;
    S(int _t, int _x, int _sy, int _ey){
        t = _t;
        x = _x;
        sy = _sy;
        ey = _ey;
    }
    bool operator<(const S& b) const{
        if(x == b.x)
            return t > b.t;
        return x < b.x;
    }
};
namespace SEG{
    int val[65536], lazy[65536];
    void init(){
        memset(val, 0, sizeof(val));
        memset(lazy, 0, sizeof(lazy));
    }
    void update(int now, int l, int r, int ql, int qr, int k){
        if(r <= ql || qr <= l) return;
        if(ql <= l && r <= qr){
            lazy[now]+=k;
            val[now] = r - l;
            return;
        }
        int mid = (l+r) / 2;
        update(now*2, l, mid, ql, qr, k);
        update(now*2+1, mid, r, ql, qr, k);
        if(lazy[now])
            val[now] = r - l;
        else
            val[now] = val[now*2] + val[now*2+1];
    }
};

void Solve(){
    int n;
    scanf("%d", &n);
    vector<int> x, y;
    vector<S> s;
    int sx, sy, ex, ey;
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        x.push_back(sx); x.push_back(ex);
        y.push_back(sy); x.push_back(ey);
        s.push_back(S(1, sx, sy, ey+1));
        s.push_back(S(-1, ex, sy, ey+1));
    }
    sort(ALL(x)); sort(ALL(y));
    x.resize(unique(ALL(x))-x.begin());
    y.resize(unique(ALL(y))-y.begin());
    for(int i = 1 ; i < (int)x.size() ; i++){
        s.push_back(S(0, x[i], 0, 0));
        printf("%d ", x[i]);
    }
    printf("\n");
    sort(ALL(s));
    int ans = 0;
    for(int i = 0 ; i < (int)s.size() ; i++){
        S &tmp = s[i];
        printf("%d %d %d %d\n", tmp.t, tmp.x, tmp.sy, tmp.ey);
        if(tmp.t != 0){
            SEG::update(1, 0, 32768, tmp.sy, tmp.ey, tmp.t);
        } else {
            ans += SEG::val[1] * (tmp.x - *(lower_bound(ALL(x), tmp.x) - 1));
        }
        printf("%d %d\n", ans, SEG::val[1]);
    }
    printf("%d\n", ans);
}
int main(){
    freopen("pa.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
}
