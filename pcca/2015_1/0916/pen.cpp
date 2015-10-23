#include <bits/stdc++.h>
using namespace std;
#define MAX 131072
#define SMAX 262144
typedef long long ll;

struct S{
    int x, sy, ey, v;
    S(){}
    S(int _x, int _sy, int _ey, int _v):
        x(_x), sy(_sy), ey(_ey), v(_v){} 
    bool operator<(const S &b) const {
        return x < b.x;
    }
};
vector<int> x, y;
namespace Seg{
    struct Node{
        int v, maxv, sz;
    };
    Node v[SMAX * 2];
    
    void init(){
        for(int i = 2 * SMAX - 1 ; i >= SMAX ; i--){
            v[i].v = v[i].maxv = 0;
            v[i].sz = 0;
        }
        for(int i = 1 ; i < (int)y.size() ; i++){
            v[i+SMAX-1].sz = y[i] - y[i-1];
        }
        for(int i = SMAX - 1 ; i > 0 ; i--){
            v[i].v = v[i].maxv = 0;
            v[i].sz = v[2*i].sz + v[2*i+1].sz;
        }
    }
    void update(int now, int l, int r, int ql, int qr, int add){
        if(r <= ql || qr <= l) return;
        if(ql <= l && r <= qr){
            v[now].v += add;
            v[now].maxv += add;
            return;
        }
        int mid = (l+r) / 2;
        update(now*2, l, mid, ql, qr, add);
        update(now*2+1, mid, r, ql, qr, add);
        v[now].maxv = max(v[now*2].maxv, v[now*2+1].maxv) + v[now].v;
        if(v[now*2].maxv == v[now*2+1].maxv)
            v[now].sz = v[now*2].sz + v[now*2+1].sz;
        else if(v[now*2].maxv > v[now*2+1].maxv)
            v[now].sz = v[now*2].sz;
        else
            v[now].sz = v[now*2+1].sz;
    }
};
void Solve(){
    x.clear(), y.clear();
    int n;
    scanf("%d", &n);
    int sx, sy, ex, ey, v;
    vector<S> s;
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d%d%d%d", &sx, &sy, &ex, &ey, &v);
        x.push_back(sx), x.push_back(ex);
        y.push_back(sy), y.push_back(ey);
        s.push_back(S(sx, sy, ey, v));
        s.push_back(S(ex, sy, ey, -v));
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    y.resize(unique(y.begin(), y.end()) - y.begin());
    Seg::init();
    sort(s.begin(), s.end());
    ll maxv = 0, maxsz = 0;
    for(int i = 0 ; i < (int)s.size() ; i++){
        if(i){
            if(s[i].x != s[i-1].x){
                if(maxv < Seg::v[1].maxv){
                    maxv = Seg::v[1].maxv;
                    maxsz = 0;
                }
                if(maxv == Seg::v[1].maxv)
                    maxsz += ll(Seg::v[1].sz) * ll(s[i].x - s[i-1].x);
            }
        }
        sy = lower_bound(y.begin(), y.end(), s[i].sy) - y.begin();
        ey = lower_bound(y.begin(), y.end(), s[i].ey) - y.begin();
        Seg::update(1, 0, SMAX, sy, ey, s[i].v);
    }
    printf("%lld %lld\n", maxv, maxsz);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
