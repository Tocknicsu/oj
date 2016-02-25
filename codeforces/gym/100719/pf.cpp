#include <bits/stdc++.h>
using namespace std;

char table[128][128];
char cmd[16];
int cmd_len;
int n, m;
int ex, ey;
int dp[128][128][4][16];
// 1 answer
// -1 answer
const int D[4][2] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

int dfs(int x, int y, int d = 0, int p = 0){
    if(x == ex && y == ey)
        return dp[x][y][d][p] = 1;
    if(dp[x][y][d][p])
        return dp[x][y][d][p] == 1;
    dp[x][y][d][p] = -1;
    int nx = x;
    int ny = y;
    int nd = d;
    int np = (p + 1) % cmd_len;
    if(cmd[p] == 'S'){
        nx = x + D[d][0];
        ny = y + D[d][1];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m){
            nx = x;
            ny = y;
        }
        if(table[nx][ny] == 'X'){
            nx = x;
            ny = y;
        }
    }
    if(cmd[p] == 'L')
        nd = (d - 1 + 4) % 4;
    if(cmd[p] == 'R')
        nd = (d + 1) % 4;
    if(dfs(nx, ny, nd, np) == 1)
        dp[x][y][d][p] = 1;
    return dp[x][y][d][p] == 1;
}


int main(){
    //freopen("pf.in", "r", stdin);
    while(~scanf("%d%d", &n, &m)){
        int expect = n * m;
        for(int i = 0 ; i < n ; i++){
            scanf("%s", table[i]);
            for(int j = 0 ; j < m ; j++)
                if(table[i][j] == 'E'){
                    ex = i;
                    ey = j;
                } else if(table[i][j] == 'X') {
                    expect--;
                }
        }
        scanf("%d%s", &cmd_len, cmd);
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++){
                if(table[i][j] == 'X') continue;
                dfs(i, j);
                if(dp[i][j][0][0] == 1){
                    ans++;
                }
            }
        if(ans == expect){
            printf("OK\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
