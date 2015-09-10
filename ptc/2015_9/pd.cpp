#include <bits/stdc++.h>
using namespace std;
namespace KM{
    const int INF = 1029384756;
    int Nx, Ny;
    int mp[510][510];
    bool visx[510], visy[510];
    int lx[510],ly[510], slack[510];
    int mx[510],my[510];
    void init(int x, int y){
        Nx = x, Ny = y;
        memset(mp,0,sizeof(mp));
        memset(mx,-1,sizeof(mx));
        memset(my,-1,sizeof(my));
        fill(lx, lx+510, -INF);
        memset(ly,0,sizeof(ly));
        memset(slack,0,sizeof(slack));
    }
    void add(int x, int y, int w){
        mp[x][y] = w;
    }

    bool Match(int x){
        visx[x] = 1;
        for(int i=0;i<Ny;i++){
            int y = i;
            if(visy[y]) continue;
            if(lx[x] + ly [y] > mp[x][y])
                slack[y] = min(slack[y], lx[x] + ly[y] - mp[x][y]);
            else{
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
        for(int i=0;i<Nx;i++)
            for(int j=0;j<Ny;j++)
                lx[i] = max(lx[i], mp[i][j]);
        for(int i=0;i<Nx;i++){
            memset(slack,0x3f,sizeof(slack));
            while(true){
                memset(visx,0,sizeof(visx));
                memset(visy,0,sizeof(visy));
                if(Match(i)) break;
                int d = INF;
                for(int j=0;j<Ny;j++)
                    if(!visy[j]) d = min(d, slack[j]);
                if(d == INF)break;
                for(int i=0;i<Nx;i++)
                    if(visx[i]) lx[i] -= d;
                for(int i=0;i<Ny;i++)
                    if(visy[i]) ly[i] += d;
                    else slack[i] -= d;
            }
        }
        int res = 0;
        for(int i=0;i<Nx;i++)
            if(mx[i] != -1)
                res += mp[i][mx[i]];
        return res;
    }
};
int v1[510],v2[510];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int x, y;
        scanf("%d%d", &x, &y);
        KM::init(x,y);
        for(int i = 0 ; i < x ; i++)
            scanf("%d", &v1[i]);
        for(int i = 0 ; i < y ; i++)
            scanf("%d", &v2[i]);
        for(int i = 0 ; i < x ; i++){
            for(int j = 0 ; j < y ; j++){
                int tmp;
                scanf("%1d", &tmp);
                if(tmp)
                    KM::add(i,j,v1[i]+v2[j]);
            }
        }
        int ans = KM::Solve();
        printf("%d\n", ans);
    }
    return 0;
}
