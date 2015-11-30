#include <bits/stdc++.h>
using namespace std;

char t[12][12];
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n, m;
bool dp[12][12][4];
int main(){
//    freopen("pj.in", "r", stdin);
    scanf("%d%d", &n, &m);
    int x, y, dir;
    for(int i = 0 ; i < n ; i++){
        scanf("%s", t[i]);
        for(int j = 0 ; j < m ; j++){
            if(t[i][j] != '.' && t[i][j] != '*'){
                x = i, y = j;
                switch(t[i][j]){
                    case 'U': dir = 0; break;
                    case 'R': dir = 1; break;
                    case 'D': dir = 2; break;
                    case 'L': dir = 3; break;
                }
            }
        }
    }
    int ans = 0;
    bool flag = 1;
    while(flag){
        if(dp[x][y][dir]) break;
        flag = 0;
        t[x][y] = '-';
        dp[x][y][dir] = 1;
        for(int i = 0 ; i < 4 ; i++){
            int next_dir = (dir+i) % 4;
            int nx = x + d[next_dir][0];
            int ny = y + d[next_dir][1];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(t[nx][ny] == '*')continue;
            flag = 1;
            x = nx;
            y = ny;
            dir = next_dir;
            break;
        }
    }
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            ans += t[i][j] == '-';
    printf("%d\n", ans);
    return 0;
}
