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
void Solve(){
    int n;
    scanf("%d", &n);
    vector<int> x, y;
    vector<S> s;
    int sx, sy, ex, ey;
    int nsx, nsy, nex, ney;
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        nsx = min(sx, ex);
        nex = max(sx, ex);
        nsy = min(sy, ey);
        ney = max(sy, ey);
        x.push_back(sx); x.push_back(ex);
        y.push_back(sy); y.push_back(ey);
        s.push_back(S(1, nsx, nsy, ney));
        s.push_back(S(-1, nex, nsy, ney));
    }
    sort(ALL(x)); sort(ALL(y));
    x.resize(unique(ALL(x))-x.begin());
    for(int i = 1 ; i < (int)x.size() ; i++){
        s.push_back(S(2, x[i], 0, 0));
    }
    sort(ALL(s));
    int ans = 0;
    map<int, int> m;
    for(int i = 0 ; i < (int)s.size() ; i++){
        S &tmp = s[i];
        if(tmp.t != 2){
            m[tmp.sy]+=tmp.t;
            m[tmp.ey]-=tmp.t;
        } else {
            int val = 0;
            int num = 0, last = 0;
            for(map<int, int>::iterator it = m.begin() ; it != m.end() ; ++it){
                if(num){
                    val += it->first - last;
                }
                last = it->first;
                num += it->second;
            }
            ans += val * (tmp.x - *(lower_bound(ALL(x), tmp.x)-1));
        }
    }
    printf("%d\n", ans);
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
}
