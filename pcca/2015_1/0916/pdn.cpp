#include <bits/stdc++.h>
using namespace std;
#define MAX 1024
#define f first
#define s second
namespace DS{
    int v[131072];
    void init(int n){
        for(int i = 0 ; i < n ; i++)
            v[i] = i;
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    void merge(int x, int y){
        v[find(x)] = find(y);
    }
};
typedef pair<int, int> PII;
PII t[MAX][MAX];    //f: dis s: source
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main(){
    int n;
    //freopen("pd.in", "r", stdin);
    while(~scanf("%d", &n)){
        int x, y;
        DS::init(n+1);
        queue<PII> Q;
        memset(t, 0, sizeof(t));
        for(int i = 1 ; i <= n ; i++){
            scanf("%d%d", &x, &y);
            if(t[x][y].s == 0){
                t[x][y] = PII(0, i);
                Q.push(PII(x, y));
            }
        }
        int ans = 0;
        while(Q.size()){
            PII now = Q.front(); Q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nx = now.f + d[i][0];
                int ny = now.s + d[i][1];
                if(nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue;
                if(t[nx][ny].s == -1){
                    t[nx][ny] = PII(t[now.f][now.s].f+1, t[now.f][now.s].s);
                    Q.push(PII(nx, ny));
                } else {
                    if(DS::find(t[now.f][now.s].s) != DS::find(t[nx][ny].s)){
                        ans += t[now.f][now.s].f + t[nx][ny].f + 1;
                        DS::merge(t[now.f][now.s].s, t[nx][ny].s);
                    }
                }
            }
        }
        printf("%d\n", ans);
        //printf("%d %d\n", ans, num);
    }
    return 0;
}
