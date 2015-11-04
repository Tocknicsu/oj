#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
char mc[16][128][128];
int dis[16][128][128];
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
typedef pair<int, int> PII;
struct P{
    int f, x, y;
    P(){}
    P(int _f, int _x, int _y) : f(_f), x(_x), y(_y){}
};
void Solve(){
    int f, x, y, n, t;
    scanf("%d%d%d%d%d", &f, &x, &y, &n, &t);
    memset(dis, -1, sizeof(dis));
    queue<P> Q;
    for(int i = 1 ; i <= f ; i++)
        for(int j = 1 ; j <= x ; j++){
            scanf("%s", mc[i][j]+1);
            for(int k = 1 ; k <= y ; k++){
                if(mc[i][j][k] == 'S'){
                    Q.push(P(i, j, k));
                    dis[i][j][k] = 0;
                }
            }
        }
    while(Q.size()){
        P now = Q.front(); Q.pop();
        char c_now = mc[now.f][now.x][now.y];
        for(int i = 0 ; i < 4 ; i++){
            int nf = now.f;
            int nx = now.x + d[i][0];
            int ny = now.y + d[i][1];
            if(nx <= 0 || ny <= 0 || nx > x || ny > y) continue;
            if(mc[nf][nx][ny] == 'X') continue;
            if(dis[nf][nx][ny] != -1) continue;
            dis[nf][nx][ny] = dis[now.f][now.x][now.y] + 1;
            Q.push(P(nf, nx, ny));
        }
        if(c_now == 'U'){
            if(dis[now.f+1][now.x][now.y] == -1){
                dis[now.f+1][now.x][now.y] = dis[now.f][now.x][now.y] + 1;
                Q.push(P(now.f+1, now.x, now.y));
            }
        } else if(c_now == 'D') {
            if(dis[now.f-1][now.x][now.y] == -1){
                dis[now.f-1][now.x][now.y] = dis[now.f][now.x][now.y] + 1;
                Q.push(P(now.f-1, now.x, now.y));
            }
        }
    }
    vector<PII> v;
    for(int i = 0 ; i < n ; i++){
        int sf, sx, sy, ss;
        scanf("%d%d%d%d", &sf, &sx, &sy, &ss);
        if(dis[sf][sx][sy] != -1)
            v.push_back(PII(3*dis[sf][sx][sy], ss));
    }
    vector<int> dp(t+1);
    for(int i = 0 ; i < (int)v.size() ; i++){
        for(int j = t ; j >= v[i].f ; j--)
            dp[j] = max(dp[j], dp[j-v[i].f]+v[i].s);
    }
    printf("%d\n", dp[t]);
}

int main(){
//    freopen("pj.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
