#include <bits/stdc++.h>
using namespace std;
#define MAX 1048576
typedef long long ll;
int v[MAX];

namespace BIT{
    int x[MAX];
    void init(){
        memset(x, 0, sizeof(x));
    }
    int query(int n){
        int re = 0;
        for( ; n > 0 ; n -= (n & (-n)))
            re += x[n];
        return re;
    }
    void add(int n){
        for( ; n < MAX ; n += (n & (-n)))
            x[n] += 1;
    }
};

void Solve(){
    BIT::init();
    int n;
    scanf("%d", &n);
    vector<int> _v;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &v[i]);
        _v.push_back(v[i]);
    }
    sort(_v.begin(), _v.end());
    _v.resize(unique(_v.begin(), _v.end()) - _v.begin());
    ll ans = 0;
    for(int i = n - 1 ; i >= 0 ; i--){
        int x = lower_bound(_v.begin(), _v.end(), v[i]) - _v.begin() + 1;
        ans += BIT::query(x-1);
        BIT::add(x);
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
