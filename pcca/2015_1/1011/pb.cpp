#include <bits/stdc++.h>
using namespace std;
vector<int> ed[1024];
bool v[1024];
int deg[1024];
queue<int> Q;
void dfs(int x){
    v[x] = true;
    for(int i = 0 ; i < (int)ed[x].size() ; i++){
        deg[ed[x][i]]--;
        if(!deg[ed[x][i]])
            Q.push(ed[x][i]);
    }
    for(int i = 0 ; i < (int)ed[x].size() ; i++){
        if(!v[ed[x][i]]){
            dfs(ed[x][i]);
            return;
        }
    }
}
int main(){
//    freopen("pb.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        int tmp;
        scanf("%d", &tmp);
        int b;
        for(int j = 0 ; j < tmp ; j++){
            scanf("%d", &b);
            deg[b]++;
            ed[i].push_back(b);
        }
    }
    for(int i = 0 ; i < n ; i++)
        if(!deg[i])
            Q.push(i);
    int ans = 0;
    while(Q.size()){
        int x = Q.front(); Q.pop();
        if(v[x]) continue;
        dfs(x);
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
