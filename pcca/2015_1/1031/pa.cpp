#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int v[64][64];
int n, m;

bool ok(int x, int y){
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(v[x][y] < v[nx][ny]) return false;
    }
    return true;
}
bool gg(int x, int y){
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(v[nx][ny] < v[x][y]) return false;
    }
    return true;
}

ll dfs(int x, int y){
    if(gg(x, y)){
        return 1;
    }
    int ans = 0;
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(v[x][y] > v[nx][ny])
            ans += dfs(nx, ny);
    }
    return ans;
}

ll Solve(){
    ll re = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            scanf("%d", &v[i][j]);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(ok(i, j)){
                re += dfs(i, j);
            }
        }
    }
            
    return re;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i < t ; i++){
        printf("Case #%d: %lld\n", i, Solve());
    }
    return 0;
}
