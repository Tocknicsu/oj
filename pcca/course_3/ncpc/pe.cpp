#include <cstdio>
#include <vector>
using namespace std;
int n, m, s, t;
int ans;
vector<int> ed[16];
bool use[16];
void dfs(int now){
    if(now == t){
        ans++;
        return;
    }
    use[now] = true;
    for(int i = 0 ; i < (int)ed[now].size() ; i++){
        if(!use[ed[now][i]])
            dfs(ed[now][i]);
    }
    use[now] = false;
}
void Solve(){
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i = 1 ; i <= n ; i++){
        int tmp, p;
        scanf("%d", &tmp);
        ed[i].clear();
        for(int j = 0 ; j < tmp ; j++){
            scanf("%d", &p);
            ed[i].push_back(p);
        }
    }
    ans = 0;
    dfs(s);
    printf("%d\n", ans);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
