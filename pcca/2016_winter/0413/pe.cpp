#include <bits/stdc++.h>
using namespace std;
#define MAX 32
#define f first
#define s second
typedef pair<int, int> PII;
char t[MAX][MAX];
int M[MAX][MAX];
int T[MAX];
int n, m;
int MASK;
int sx, sy;
int take;
int D[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};
int ed[MAX][MAX];
void build(PII start){
    int v[MAX][MAX] = {};
    queue<PII> Q;
    Q.push(start);
    while(Q.size()){
        PII now = Q.front(); Q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = now.f + D[i][0];
            int ny = now.s + D[i][1];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(PII(nx, ny) == start) continue;
            if(M[nx][ny] == -1) continue;
            if(v[nx][ny]) continue;
            v[nx][ny] = v[now.f][now.s] + 1;
            Q.push(PII(nx, ny));
        }
    }
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++){
            if(t[i][j] == 'G' || t[i][j] == 'S'){
                if(v[i][j] == 0)
                ed[M[i][j]][M[start.f][start.s]] = 1029384756;
                else
                ed[M[i][j]][M[start.f][start.s]] = v[i][j];
            }
        }
}

int dp[MAX][1 << 16];
bool check(int guess){
    queue<PII> Q;
    memset(dp, 0, sizeof(dp));
    dp[20][0] = guess;
    Q.push(PII(20, 0)); 
    while(Q.size()){
        PII now = Q.front();
        Q.pop();
        for(int i = 0 ; i < take ; i++){
            if( (1 << i) & now.s) continue;
            if( (now.s & MASK) == MASK) return true;
            if(ed[now.f][i] <= dp[now.f][now.s]){
                int state = now.s + (1 << i);
                if(T[i])
                    dp[i][state] = guess;
                else
                    dp[i][state] = dp[now.f][now.s] - ed[now.f][i];
                Q.push(PII(i, now.s + (1 << i)));
            }
        }
    }
    return false;
}
void Solve(){
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < n ; i++)
        scanf("%s", t[i]);
    MASK = 0;
    take = 0;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++){
            if(t[i][j] == 'H'){
                M[i][j] = 20;
                sx = i, sy = j;
            } else if(t[i][j] == '.'){
                M[i][j] = 100;
            } else if(t[i][j] == 'S'){
                M[i][j] = take;
                T[take] = 0;
                MASK |= (1 << take);
                take++;
            } else if(t[i][j] == 'G'){
                M[i][j] = take;
                T[take] = 1;
                take++;
            } else if(t[i][j] == 'V'){
                M[i][j] = -1;
            }
        }
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            if(t[i][j] == 'G' || t[i][j] == 'S' || t[i][j] == 'H')
                build(PII(i, j));
    int now = 0, step = 128;
    while(step){
        if( check(now+step) ){
            step >>= 1;
        } else {
            now += step;
        }
        if(now >= 255){
            printf("-1\n");
            return;
        }
    }
    printf("%d\n", now+1);
}

int main(){
    int cases;
    scanf("%d", &cases);
    while(cases--)
        Solve();
    return 0;
}
