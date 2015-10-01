#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 131072
#define ALL(v) v.begin(), v.end()
namespace Seg{
    struct Node{
        int v;
        int mv;
        int sz;
    };
    Node v[MAX * 4];
    void init(){
        for(int i = 262144 ; i < MAX ; i++){
            v[i].v = v[i].mv = 0;
            v[i].sz = 1;
        }
        for(int i = 262144 - 1 ; i > 0 ; i--){
            v[i].v = v[i].mv = 0;
            v[i].sz = v[i*2].sz * 2;;
        }
    }
    void update(int now, int l, int r, int ql, int qr, int add){
        //cout << now << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << add << endl;
        if(r <= ql || qr <= l) return;
        if(ql <= l && r <= qr){
            v[now].v += add;
            v[now].mv += add;
            return;
        }
        int mid = (l+r) / 2;
        //down
        v[now*2].v += add;
        v[now*2].mv += add;
        v[now*2+1].v += add;
        v[now*2+1].mv += add;
        v[now].v = 0;
        update(now*2, l, mid, ql, qr, add);
        update(now*2+1, mid, r, ql, qr, add);
        //up
        v[now].mv = max(v[now*2].mv, v[now*2+1].mv);
        if(v[now].mv == v[now*2].mv)
            v[now].sz += v[now*2].sz;
        if(v[now].mv == v[now*2+1].mv)
            v[now].sz += v[now*2+1].sz;
    }
};

struct S{
    int x, sy, ey, tag, value;
    S(){}
    S(int _x, int _sy, int _ey, int _tag, int _value){
        x = _x;
        sy = _sy;
        ey = _ey;
        tag = _tag;
        value = _value;
    }
    bool operator<(const S& b) const {
        if(x == b.x)
            return tag > b.tag;
        return x < b.x;
    }
};

void Solve(){
    Seg::init();
    int n;
    scanf("%d", &n);
    vector<S> s;
    vector<int> x, y;
    for(int i = 0 ; i < n ; i++){
        int sx, sy, ex, ey, v;
        scanf("%d%d%d%d%d", &sx, &sy, &ex, &ey, &v);
        s.push_back(S(sx, sy, ey, 1, v));
        s.push_back(S(ex, sy, ey, -1, -v));
        x.push_back(sx); x.push_back(ex);
        y.push_back(sy); y.push_back(ey);
    }
    sort(ALL(x)); sort(ALL(y));
    x.resize(unique(ALL(x))-x.begin());
    y.resize(unique(ALL(y))-y.begin());
    for(int i = 1 ; i < (int)x.size() ; i++)
        s.push_back(S(i, 0, 0, 0, 0));
    sort(ALL(s));
    ll ans = 0, mans = 0;
    for(int i = 0 ; i < (int)s.size() ; i++){
        S now = s[i];
        if(now.tag == 0){
            if(Seg::v[1].mv > mans){
                ans = 0;
                mans = Seg::v[1].mv;
            }
            if(Seg::v[1].mv == mans){
                ans = ans + ll(x[s[i].x]-x[s[i].x-1]) * ll(Seg::v[1].sz);
                cout << "*" << ans << ' ' << mans << endl;
                cout << Seg::v[1].sz << endl;
            }
        } else {
            int _sy = lower_bound(ALL(y), now.sy) - y.begin();
            int _ey = lower_bound(ALL(y), now.ey) - y.begin();
            Seg::update(1, 1, MAX, _sy, _ey+1, now.value);
        }
    }
    printf("%lld %lld\n", ans, mans);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
