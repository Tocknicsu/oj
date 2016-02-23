#include <bits/stdc++.h>
using namespace std;
#define MAX 131072
typedef long long ll;

namespace BIT{
    int v[MAX];
    void init(){
        memset(v, 0, sizeof(v));
    }
    void add(int x){
        for( ; x < MAX ; x += x & -x)
            v[x]++;
    }
    int query(int x){
        int re = 0;
        for( ; x > 0 ; x -= x & -x)
            re += v[x];
        return re;
    }
};

int v[MAX];


void Solve(){
    int n, x;
    scanf("%d", &n);
    unordered_map<int, int> u;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &x);
        u[x] = i + 1;
    }
    ll ans = 0;
    BIT::init();
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &v[i]);
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        ans += BIT::query(u[v[i]]);
        BIT::add(u[v[i]]);
    }
    printf("%lld\n", ans);
}


int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
