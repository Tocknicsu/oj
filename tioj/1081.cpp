#include <bits/stdc++.h>
using namespace std;
#define MAX 1024
#define f first
#define s second
int d[9][2];
typedef pair<int, int> PII;
int t[MAX][MAX];
int main(){
    for(int i = -1 ; i < 2 ; i++)
        for(int j = -1 ; j < 2 ; j++){
            d[(i+1)*3+(j+1)][0] = i;
            d[(i+1)*3+(j+1)][1] = j;
        }
    int n, m;
    while(scanf("%d%d", &n, &m), n && m){
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                scanf("%1d", &t[i][j]);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++)
                if(t[i][j]){
                    ans++;
                    queue<PII> Q;
                    t[i][j] = 0;
                    Q.push(PII(i, j));
                    while(Q.size()){
                        PII now = Q.front(); Q.pop();
                        for(int k = 0 ; k < 9 ; k++){
                            int nx = now.f + d[k][0];
                            int ny = now.s + d[k][1];
                            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if(!t[nx][ny]) continue;
                            t[nx][ny] = 0;
                            Q.push(PII(nx, ny));
                        }
                    }
                }
        }
        printf("%d\n", ans);
    }
            
    return 0;
}
