#include <bits/stdc++.h>
using namespace std;
int deg[1024];
int ed[1024][1024];
bool v[1024];
int n;
bool dfs(int x){
    int flag = !v[x];
    v[x] = true;
    for(int i = 0 ; i < n ; i++){
        if((ed[x][i]==1 && !v[i]) || (ed[x][i]==-1 && v[i])){
            if(dfs(i)){
                ed[x][i] *= -1;
                return true;
            }
        }
    }
    return flag;
}
int main(){
    //freopen("pb.2.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        int tmp;
        scanf("%d", &tmp);
        int b;
        for(int j = 0 ; j < tmp ; j++){
            scanf("%d", &b);
            deg[b]++;
            ed[i][b] = 1;
        }
    }
    vector<int> p;
    for(int i = 0 ; i < n ; i++)
        if(!deg[i])
            p.push_back(i);
    for(int i = 0 ; i < n ; i++){
        int now = p[i];
        for(int j = 0 ; j < n ; j++){
            if(ed[now][j]){
                deg[j]--;
                if(!deg[j])
                    p.push_back(j);
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(!v[p[i]]){
            ans++;
            dfs(p[i]);
        }
    }
    printf("%d\n", ans);
}
