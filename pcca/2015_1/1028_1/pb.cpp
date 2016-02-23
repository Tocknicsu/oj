#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<ll, ll> PLL;
bool cmp(const PLL &a, const PLL &b){
    return a.s > b.s;
}

int main(){
    int n;
    scanf("%d", &n);
    vector<PLL> v(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%I64d%I64d", &v[i].f, &v[i].s);
        if(v[i].s > v[i].f) swap(v[i].f, v[i].s);
    }
    sort(v.begin(), v.end(), cmp);
    PLL ans;
    ll value = 0;
    for(int i = 0 ; i < n ; i++){
        int cnt = 0;
        for(int j = 0 ; j < n ; j++){
            if(v[j].f >= v[i].f) 
                cnt++;
            if(v[j].s * v[i].f * cnt > value){
                ans = PLL(v[i].f, v[j].s);
                value = v[j].s * v[i].f * cnt;
            }
        }
    }
    printf("%I64d\n%I64d %I64d\n", value, ans.f, ans.s);
    return 0;
}
