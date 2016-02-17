#include <iostream>
#include <vector>
using namespace std;

const int INF = 1024;

int dp[128][3];
vector<int> ed[128];

void dfs(int x){
    dp[x][1] = dp[x][2] = INF;
    dp[x][0] = 1;
    if(ed[x].size() == 0){
    } else if(ed[x].size() == 1) {
        int u = ed[x][0];
        dfs(u);
        dp[x][0] += min(dp[u][0], min(dp[u][1], dp[u][2]));
        dp[x][1] = dp[u][0];
    } else {
        int cnt = 0, total = 0, ma = INF, mb = INF;
        for(int i = 0 ; i < (int)ed[x].size() ; i++){
            int u = ed[x][i];
            dfs(u);
            dp[x][0] += min(dp[u][0], min(dp[u][1], dp[u][2]));
            if(dp[u][0] <= dp[u][2]){
                cnt++;
                total += dp[u][0];
            } else {
                total += dp[u][2];
                int tmp = dp[u][0] - dp[u][2];
                if(tmp <= ma){
                    mb = ma;
                    ma = tmp;
                } else if(tmp <= mb){
                    mb = tmp;
                }
            }
        }
        dp[x][1] = dp[x][2] = total;
        if(cnt == 0){
            dp[x][1] += ma;
            dp[x][2] += ma + mb;
        } else if(cnt == 1){
            dp[x][2] += ma;
        }
    }
    //printf("%d: %d %d %d\n", x, dp[x][0], dp[x][1], dp[x][2]);
}

void Solve(){
    int n;
    scanf("%d", &n);
    int t;
    for(int i = 1 ; i <= n ; i++){
        ed[i].clear();
        scanf("%d", &t);
        if(i == 1) continue;
        ed[t].push_back(i);
    }
    dfs(1);
    printf("%d\n", min(dp[1][0], dp[1][2]));
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
