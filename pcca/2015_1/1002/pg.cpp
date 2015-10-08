#include <bits/stdc++.h>
using namespace std;
namespace Bimatch{
    int nx, ny;
    bool ed[1024][1024];
    int mx[1024], my[1024];
    int visy[1024];
    void init(int _nx, int _ny){
        nx = _nx, ny = _ny;
        memset(ed, 1, sizeof(ed));
    }
    void add(int a, int b){
        ed[a][b] = 0;
    }
    bool Match(int x){
        for(int y = 1 ; y <= ny ; y++){
            if(ed[x][y] && !visy[y]){
                visy[y] = 1;
                if(my[y] == -1 || Match(my[y])){
                    mx[x] = y, my[y] = x;
                    return true;
                }
            }
        }
        return false;
    }
    int Solve(){
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
        int ans = 0;
        for(int i = 1 ; i <= nx ; i++){
            memset(visy, 0, sizeof(visy));
            ans += Match(i);
        }
        return ans;
    }
};
void Solve(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    Bimatch::init(n, m);
    for(int i = 0 ; i < k ; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        Bimatch::add(a, b);
    }
    printf("%d\n", max(n, max(m, n+m-Bimatch::Solve())));
}

int main(){
//    freopen("pg.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
