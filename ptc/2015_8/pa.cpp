#include <bits/stdc++.h>
using namespace std;
#define INF 1029384756
#define MAX 256

int n, adj[MAX][MAX];
int vx[MAX], vy[MAX];
int mx[MAX], my[MAX];
bool visx[MAX], visy[MAX];

bool dfs(int x){
    visx[x] = true;
    for(int i = 1 ; i <= n ; i++) 
        if(!visy[i] && vx[x] + vy[i] == adj[x][i]){
            visy[i] = 1;
            if(my[i] == -1 || dfs(my[i])){
                my[i] = x;
                mx[x] = i;
                return true;
            }
        }
    return 0;
}
void update(){
    int a = 0;
    for(int i = 1 ; i <= n ; i++){
        if(visx[i])
            for(int j = 1 ; j <= n ; j++){
                if(!visy[j])
                    a = max(a, vx[i]+vy[j]-adj[i][j]);
            }
    }
    for(int i = 1 ; i <= n ; i++){
        if(visx[i]) vx[i] -= a;
        if(visy[i]) vy[i] -= a;
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++){
                scanf("%d", &adj[i][j]);
            }
        for(int i = 1 ; i <= n ; i++){
            vx[i] = 0;
            int m=-1;
            for(int j = 1 ; j <= n ; j++)
                m = max(m, adj[j][i]);
            vy[i] = m;
        }
        memset(mx, INF, sizeof(mx));
        memset(my, INF, sizeof(my));
        for(int i = 1 ; i <= n ; i++){
            while(1){
                memset(visx, 0, sizeof(visx));
                memset(visy, 0, sizeof(visy));
                if(!dfs(i)) update();
                else break;
            }
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; i++) ans += adj[i][mx[i]];
        printf("%d\n", ans);
    }
}
