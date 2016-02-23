#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> PII;

int squ(int x){
    return x * x;
}

int dis(PII &a, PII &b){
    return squ(a.f - b.f) + squ(a.s - b.s);
}

ll Solve(){
    int n;
    scanf("%d", &n);
    vector<PII> p(n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d%d", &p[i].f, &p[i].s);

    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        unordered_map<int, ll> m;
        for(int j = 0 ; j < n ; j++){
            if(i == j) continue;
            m[dis(p[i], p[j])]++;
        }
        for(auto x : m){
            if(x.s >= 2)
                ans += x.s * (x.s - 1) / 2;
        }
    }
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++)
        printf("Case #%d: %lld\n", i, Solve());
    return 0;
}
