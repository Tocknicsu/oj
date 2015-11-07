#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
int n, m;
vector<PII> ed[16384];
int cnt;
bool ok[16384];
int v[16384];
int low[16384];

void dfs(int x, int med){
    v[x] = ++cnt;
    for(int i = 0 ; i < (int)ed[x].size() ; i++){
        PII &e = ed[x][i];
        if(e.s == med) continue;
        if(v[e.f] == -1){
            dfs(e.f, e.s);
            low[x] = min(low[x], low[e.f]);
        } else {
            low[x] = min(low[x], v[e.f]);
        }
    }
    if(low[x] <= v[x])
        ok[x] = false;
}
int dfs2(int x){
    if(!ok[x]) return 0;
    ok[x] = false;
    int res = 1;
    for(int i = 0 ; i < (int)ed[x].size() ; i++){
        PII &e = ed[x][i];
        if(ok[e.f])
            res += dfs2(e.f);
    }
    return res;
}

int Solve(){
    scanf("%d%d", &n, &m);
    memset(ok, 1, sizeof(ok));
    memset(v, -1, sizeof(v));
    fill(low, low+16384, 1029384756);
    cnt = 0;
    int a, b, ans = 0, edcnt = 0;
    for(int i = 0 ; i < n ; i++)
        ed[i].clear();
    for(int i = 0 ; i < m ; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        ed[a].push_back(PII(b, edcnt));
        ed[b].push_back(PII(a, edcnt++));
    }
    dfs(0, -1);
    for(int i = 0 ; i < n ; i++){
        int t = dfs2(i);
        ans += t * (t-1) / 2;
    }
    return ans;
} 
int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i < t ; i++){
        printf("Case #%d: %d\n", i+1, Solve());
    }
    return 0;
}
