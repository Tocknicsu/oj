#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;
#define f first
#define s second
vector<PII> ed[65536];
int P[65536];
int GO[65536];
int pc[65536];
PII re[65536];
int total;

ll ansk;
vector<int> ans;
void dfs(int now, int p = 0){
    P[now] = p;
    for(int i = 0 ; i < (int)ed[now].size() ; i++){
        PII &e = ed[now][i];
        if(e.f == p) continue;
        dfs(e.f, now);
        re[now].f += re[e.f].f;
        re[now].s += re[e.f].s + (re[e.f].f) * e.s;
        pc[e.f] = e.s;
    }
    re[now].f += GO[now];
}
void dfs2(int now, int p = 0){
    re[now].s = re[p].s - pc[now] * re[now].f + (total - re[now].f) * pc[now];
    if(re[now].s < ansk){
        ans.clear();
        ansk = re[now].s;
    }
    if(re[now].s == ansk)
        ans.push_back(now);
    for(int i = 0 ; i < (int)ed[now].size() ; i++){
        if(ed[now][i].f != p)
            dfs2(ed[now][i].f, now);
    }
}

void Solve(){
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++){
        ed[i].clear();
        re[i] = PII(0, 0);
        GO[i] = 0;
        pc[i] = 0;
    }
    int a, b, c;
    for(int i = 1 ; i < n ; i++){
        scanf("%d%d%d", &a, &b, &c);
        ed[a].push_back(PII(b, c));
        ed[b].push_back(PII(a, c));
    }
    int m;
    scanf("%d", &m);
    for(int i = 0 ; i < m ; i++){
        scanf("%d%d", &a, &b);
        GO[a] = b;
    }
    int root = rand()%n+1;
    dfs(root);
    total = re[root].f;
    ansk = re[root].s;
    ans.clear();
    ans.push_back(root);
    for(int i = 0 ; i < (int)ed[root].size() ; i++)
        dfs2(ed[root][i].f, root);
    sort(ans.begin(), ans.end());
    printf("%I64d\n", ansk*2ll);
    for(int i = 0 ; i < (int)ans.size() ; i++)
        printf("%d ", ans[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
