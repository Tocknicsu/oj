#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
int m, n;
int k;
vector<int> v;
vector<PII> ed;
void add(int s, int e){
    ed.push_back(PII(s, 1));
    ed.push_back(PII(e, -1));
}
bool ok(int x){
    int now = 0;
    ed.clear();
    for(int i = 0 ; i < m ; i++){
        int s = v[i] - x;
        int e = v[i] + x;
        if(e >= n){
            add(s, n-1);
            add(0, e%n);
        } else if(s < 0){
            add(n+s, n-1);
            add(0, e);
        } else {
            add(s, e);
        }
    }
    sort(ed.begin(), ed.end());
    if(ed[0].f + n - ed.back().f > k){
        return false;
    }
    for(int i = 0 ; i < (int)ed.size() ; i++){
        if(i && ed[i].f - ed[i-1].f > k && now == 0)
            return false;
        if(i && ed[i].f - ed[i-1].f >= 2 * k && ed[i-1].s == 1 && now == 1)
            return false;
        now += ed[i].s;
    }
    return true;
}

void Solve(){
    scanf("%d%d", &n, &m);
    k = n / m;
    v = vector<int>(m);
    for(int i = 0 ; i < m ; i++)
        scanf("%d", &v[i]);
    int ans = 0, step = n / 2 - 1;
    while(step){
        if(ok(ans+step)){
            step >>= 1;
        } else {
            ans += step;
        }
    }
    printf("%d\n", ans+1);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i < t ; i++){
        printf("Case #%d: ", i+1);
        Solve();
    }
    return 0;
}
