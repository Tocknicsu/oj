#include <bits/stdc++.h>
using namespace std;
char s[1024][1024];
int record[1048576];
int d[9][2] = {
    {0, 0}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}
};
int main(){
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0 ; i < n ; i++){
            scanf("%s", s[i]);
        }
        int x, y, t;
        for(int i = 0 ; i < m ; i++){
            memset(record, -1, sizeof(record));
            scanf("%d%d%d", &x, &y, &t);
            int now = 0;
            while(now != t){
                if(record[x*n+y] != -1){
                    now += (t - now) / (now - record[x*n+y]) * (now - record[x*n+y]);
                    memset(record, -1, sizeof(record));
                    continue;
                }
                record[x*n+y] = now;
                now++;
                int dir = s[y][x] == 'x' ? 0 : s[y][x] - '0';
                //printf("now: %d %d dir %c %d", x, y, s[x][y], dir);
                int nx = x + d[dir][0], ny = y + d[dir][1];
                //printf("new: %d %d\n", nx, ny);
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                if(s[nx][ny] == 'x') break;
                x = nx;
                y = ny;
            }
            //printf("ans: %d %d\n", x, y);
            printf("%d %d\n", x, y);
        }
    }
}
