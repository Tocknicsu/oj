#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
#define f first
#define s second

ll d[4][2] = {
    {0ll, 1ll}, {1ll, 0ll}, {0ll, -1ll}, {-1ll, 0ll}
};
bool test(ll a, ll b, ll c, ll d){
    if(a <= c && c <= b) return true;
    if(a <= d && d <= b) return true;
    if(b <= c && c <= a) return true;
    if(b <= d && d <= a) return true;
    return false;
}
bool test2(PLL a, PLL b, PLL c){
    if(a.f == b.f && b.f == c.f){
        return (a.s <= c.s && c.s <= b.s) || (b.s <= c.s && c.s <= a.s);
    } else {
        return (a.f <= c.f && c.f <= b.f) || (b.f <= c.f && c.f <= a.f);
    }
}
bool coll(PLL a, PLL b, PLL c, PLL d){
    if(a == c || a == d || b == c || b == d) 
        return true;
    if(a.f - b.f == 0 && c.f - d.f == 0){
        return a.f == c.f && (test(a.s, b.s, c.s, d.s) || test(c.s, d.s, a.s, b.s));
    }
    if(a.s - b.s == 0 && c.s - d.s == 0){
        return a.s == c.s && (test(a.f, b.f, c.f, d.f) || test(c.f, d.f, a.f, b.f));
    }
    PLL cri;
    if(a.f - b.f == 0){
        cri.f = a.f;
        cri.s = c.s;
    } else {
        cri.f = c.f;
        cri.s = a.s;
    }
    return test2(a, b, cri) && test2(c, d, cri);
}
void Solve(int n){
    vector<PLL> v;
    PLL now = PLL(0, 0);
    v.push_back(now);
    int dir = 0;
    for(int i = 0 ; i < n ; i++){
        ll t;
        scanf("%I64d", &t);
        now.f += t * d[dir][0];
        now.s += t * d[dir][1];
        v.push_back(PLL(now.f, now.s));
        dir = (dir + 1) % 4;
    }
    for(int i = 4 ; i < (int)v.size() ; i++){
        for(int j = max(1, i - 7) ; j < i - 1 ; j++){
            if(coll(v[i-1], v[i], v[j-1], v[j])){
                printf("%d\n", i - 1);
                return;
            }
        }
    }
    printf("OK\n");
}

int main(){
//    freopen("ph.in", "r", stdin);
    int n;
    while(~scanf("%d", &n))
        Solve(n);
    return 0;
}
