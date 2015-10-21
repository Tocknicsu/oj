#include <bits/stdc++.h>
using namespace std;
vector<int> ed[131072];
int v[131072];
int deg[131072];
int local_deg[131072];
void Solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    int x, y;
    for(int i = 0 ; i < n ; i++){
        ed[i].clear();
        scanf("%d", &v[i]);
        v[i]--;
    }
    for(int i = 0 ; i < m ; i++){
        scanf("%d%d", &x, &y);
        x--, y--;
        deg[y]++;
        ed[x].push_back(y);
    }
    int now = n, flag = 0, tmp = 0, ans = 1029384756;
    queue<int> Q[2];
    for(int i = 0 ; i < n ; i++){
        local_deg[i] = deg[i];
        if(local_deg[i] == 0)
            Q[v[i]].push(i);
    }
    while(now){
        tmp++;
        while(Q[flag].size()){
            int u = Q[flag].front(); Q[flag].pop();
            now--;
            for(int i = 0 ; i < (int)ed[u].size() ; i++){
                int _v = ed[u][i];
                local_deg[_v]--;
                if(local_deg[_v] == 0)
                    Q[v[_v]].push(_v);
                
            }
        }
        flag ^= 1;
    }
    ans = min(ans, tmp);
    flag = 1;
    tmp = 0;
    now = n;
    for(int i = 0 ; i < n ; i++){
        local_deg[i] = deg[i];
        if(local_deg[i] == 0)
            Q[v[i]].push(i);
    }
    while(now){
        tmp++;
        while(Q[flag].size()){
            int u = Q[flag].front(); Q[flag].pop();
            now--;
            for(int i = 0 ; i < (int)ed[u].size() ; i++){
                int _v = ed[u][i];
                local_deg[_v]--;
                if(local_deg[_v] == 0)
                    Q[v[_v]].push(_v);
                
            }
        }
        flag ^= 1;
    }
    ans = min(ans, tmp);
    printf("%d\n", ans-1);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
