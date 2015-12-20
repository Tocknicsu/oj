#include <bits/stdc++.h>
using namespace std;
#define MAX 2048
#define INF 1029384756
typedef pair<int, int> PII;
int ed[MAX][MAX];
bool use[MAX][MAX];
int ned[MAX][MAX];
vector<PII> new_ed[MAX];

void dfs(int s, int x, int c = 0){
    if(ned[s][x] != -1) return;
    ned[s][x] = c;
    for(int i = 0 ; i < (int)new_ed[x].size() ; i++){
        dfs(s, new_ed[x][i].first, c+new_ed[x][i].second);
    }
}

struct S{
    int a, b, c;
    S(){}
    S(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};
bool cmp(const S &a, const S &b){
    return a.c < b.c;
}
namespace DS{
    int v[MAX], sz;
    void init(int _sz){
        for(int i = 0 ; i < MAX ; i++)
            v[i] = i;
        sz = _sz;
    }
    int find(int x){
        return v[x] == x ? v[x] : v[x] = find(v[x]);
    }
    bool merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return false;
        v[x] = y;
        sz--;
        return true;
    }

};
S sed[MAX * MAX];
int main(){
    //freopen("pa.in", "r", stdin);
    int n;
    while(~scanf("%d", &n)){
        memset(use, 0, sizeof(use));
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                scanf("%d", &ed[i][j]);
                sed[cnt].c = ed[i][j];
                sed[cnt].a = i;
                sed[cnt].b = j;
                cnt++;
            }
        }
        sort(sed, sed+cnt, cmp);
        DS::init(n);
        for(int i = 0 ; i < cnt && DS::sz != 1 ; i++){
            if(DS::merge(sed[i].a, sed[i].b)){
                use[sed[i].a][sed[i].b] = true;
            }
        }
        for(int i = 0 ; i < MAX ; i++)
            new_ed[i].clear();
        int sx, sy;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++){
                if(use[i][j]){
                    printf("%d %d %d\n", i+1, j+1, ed[i][j]);
                    new_ed[i].push_back(PII(j, ed[i][j]));
                    new_ed[j].push_back(PII(i, ed[i][j]));
                    sx = i, sy = j;
                }
            }
        memset(ned, -1, sizeof(ned));
        for(int i = 0 ; i < n ; i++)
            dfs(i, i);
        int need = INF, nx, ny;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++){
                if(ned[i][j] > ed[i][j] && need > ed[i][j]){
                    need = ed[i][j];
                    nx = i;
                    ny = j;
                }
            }
        if(need == INF){
            printf("%d %d %d\n", sx+1, sy+1, ed[sx][sy]);
        } else {
            printf("%d %d %d\n", nx+1, ny+1, need);
        }
        printf("\n");
    }
    return 0;
}
