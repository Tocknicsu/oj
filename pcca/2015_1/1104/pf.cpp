#include <bits/stdc++.h>
using namespace std;
#define MAX 2512
vector<int> ed[MAX];
int v[MAX];

void dfs(int x){
    for(int i = 0 ; i < (int)ed[x].size() ; i++){
        if(v[ed[x][i]]) continue;
        v[ed[x][i]] = true;
        dfs(ed[x][i]);
    }
}
void Solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < n ; i++)
        ed[i].clear();
    for(int i = 0 ; i < m ; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        ed[a].push_back(b);
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        memset(v, 0, sizeof(v));
        dfs(i);
        for(int j = 0 ; j < n ; j++){
            if(i != j)
                ans += v[j];
        }
    }
    printf("%d\n", ans);
}

int main(){
//    freopen("pf.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
