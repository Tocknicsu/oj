#include <bits/stdc++.h>
using namespace std;
int _next[1024];
int v[1024];
vector<int> ed[1024];
int dfs(int start, int now, int deep){
    if(v[now]){
        return now == start ? deep : 0;
    }
    v[now] = 1;
    int ans = dfs(start, _next[now], deep+1);
    v[now] = 0;
    return ans;
}

int dfs2(int now, int p){
    int re = 0;
    for(auto x : ed[now])
        if(x != p)
            re = max(re, dfs2(x, p));
    return re + 1;
}

void Solve(int cases){
    int sigma = 0;
    for(int i = 0 ; i < 1024 ; i++)
        ed[i].clear();
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &_next[i]);
        ed[_next[i]].push_back(i);
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        int tmp = dfs(i, i, 0);
        if(tmp == 2){
            tmp = dfs2(i, _next[i]) + dfs2(_next[i], i);
            sigma += tmp;
        }
        ans = max(ans, tmp);
    }
    ans = max(ans, sigma / 2);
    printf("Case #%d: %d\n", cases, ans);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++)
        Solve(i);
    return 0;
}
