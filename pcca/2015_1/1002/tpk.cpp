#include <bits/stdc++.h>
using namespace std;
vector<int> ed[16384];
bool use[16384];
int deg[16384];

void Solve(int n){
    memset(use, 0, sizeof(use));
    memset(deg, 0, sizeof(deg));
    for(int i = 1 ; i <= n ; i++){
        ed[i].clear();
        int now, x, t;
        scanf("%d", &now);
        scanf("%d", &x);
        for(int j = 0 ; j < x ; j++){
            scanf("%d", &t);
            ed[now].push_back(t);
            deg[t]++;
        }
    }
    queue<int> Q;
    for(int i = 1 ; i <= n ; i++)
        if(!deg[i]) Q.push(i);
    int ans = 0;
    while(Q.size()){
        ans += 1;
        int now = Q.front(); Q.pop();
        use[now] = 1;
        for(int i = 0 ; i < (int)ed[now].size() ; i++){
            deg[ed[now][i]]--;
            if(!deg[ed[now][i]])
                Q.push(ed[now][i]);
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(!use[i]){
            use[i] = 1;
            int tmp = 1;
            Q.push(i);
            while(Q.size()){
                int now = Q.front(); Q.pop();
                for(int i = 0 ; i < (int)ed[now].size() ; i++){
                    if(use[ed[now][i]]) continue;
                    Q.push(ed[now][i]);
                    use[ed[now][i]] = 1;
                    tmp++;
                }
            }
            ans += tmp * tmp;
        }
    }
    printf("%d\n", ans);
}

int main(){
    int n;
    while(scanf("%d", &n), n)
        Solve(n);
    return 0;
}
