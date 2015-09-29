#include <bits/stdc++.h>
using namespace std;
#define MAX 131072
struct S{
    int x, sy, ey, s;
    S(){}
    S(int _x, int _sy, int _ey, int _s){
        x = _x;
        sy = _sy;
        ey = _ey;
        s = _s;
    }
    bool operator<(const S& b) const {
        if(x == b.x){
            return s > b.s;
        }
        return x < b.x;
    }
};
int node[2*MAX];
void init(){
    memset(node, 0, sizeof(node));
}
void add(int k, int l, int r, int ql, int qr, int v){
    if(r <= ql || qr <= l) return;
    if(ql <= l && r <= qr){
        node[k]+=v;
        return;
    }
    int mid = (l+r) / 2;
    add(k*2, l, mid, ql, qr, v);
    add(k*2+1, mid, r, ql, qr, v);
}
int query(int k, int l, int r, int p){
    if(l+1 == r){
        return node[k];
    }
    int mid = (l+r) / 2;
    if(p < mid){
        return node[k] + query(k*2, l, mid, p);
    } else {
        return node[k] + query(k*2+1, mid, r, p);
    }
    
}

void Solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<S> v;
    for(int i = 0 ; i < n ; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        v.push_back(S(x, y, 0, 0));
    }
    for(int i = 0 ; i < m ; i++){
        int sx, sy, ex, ey;
        scanf("%d%d%d%d", &sx, &ex, &sy, &ey);
        v.push_back(S(sx, sy, ey, 1));
        v.push_back(S(ex, sy, ey, -1));
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0 ; i <(int)v.size() ; i++){
        S &now = v[i];
        if(now.s == 0){
            ans += query(1, 0, MAX, now.sy);
        } else {
            add(1, 0, MAX, now.sy, now.ey+1, now.s);
        }
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
