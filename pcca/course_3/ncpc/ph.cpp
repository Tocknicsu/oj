#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 131072
vector<int> ed[MAX];
bool crit[MAX];
int ans_pair;

void dfs(int x, int p = -1){
    for(int i = 0 ; i < (int)ed[x].size() ; i++){
        int &u = ed[x][i];
        if(u == p) continue;
        dfs(u, x);
        if(crit[u] == 0) crit[x] = 1;
    }
    if(crit[x]) ans_pair++;
}

void Solve(){
    ans_pair = 0;
    memset(crit, 0, sizeof(crit));
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        ed[i].clear();
    }
    int x;
    for(int i = 1 ; i < n ; i++){
        scanf("%d", &x);
        ed[x].push_back(i);
        ed[i].push_back(x);
    }
    dfs(0);
    vector<int> ans;
    queue<int> q;
    for(int i = 0 ; i < n ; i++)
        if(crit[i]){
            ans.push_back(i);
        }
    for(int i = 0 ; i < (int)ans.size() ; i++){
        int num = 0, tmp;
        for(int j = 0 ; j < (int)ed[i].size() ; j++){
            int &u = ed[i][j];
            if(crit[u] == 0){
                num++;
                tmp = u;
            }
        }
        if(num == 1){
            crit[tmp] = 1;
            ans.push_back(tmp);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d %d\n", ans_pair, (int)ans.size());
    for(int i = 0 ; i < min((int)ans.size(), 3) ; i++)
        printf("%d%c", ans[(int)ans.size()-i-1], i == min((int)ans.size(), 3) - 1 ? '\n' : ' ');
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
