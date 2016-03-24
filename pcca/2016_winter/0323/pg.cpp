#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define MAX 512
#define f first
#define s second
vector<PII> d[MAX];
namespace DS{
    int v[MAX];
    void init(){
        for(int i = 0 ; i < MAX ; i++)
            v[i] = i;
    }
    int find(int x){
        return x == v[x] ? v[x] : find(v[x]);
    }
    void merge(int x, int y){
        v[find(x)] = find(y);
    }
};
bool cmp(const PII &a, const PII &b){
    return a.s > b.s;
}

int main(){
    //freopen("pg.in", "r", stdin);
    int n, m, k, a, b, c;
    while(scanf("%d%d%d", &n, &m, &k), n || m || k){
        DS::init();
        for(int i = 0 ; i < MAX ; i++)
            d[i].clear();
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d", &a, &b);
            DS::merge(a, b);
        }
        for(int i = 0 ; i < k ; i++){
            scanf("%d%d%d", &a, &b, &c);
            d[DS::find(a)].push_back(PII(b, c));
        }
        int ans = 0;
        for(int i = 0 ; i < MAX ; i++){
            int now = 0;
            sort(d[i].begin(), d[i].end(), cmp);
            for(int j = 0 ; j < (int)d[i].size() ; j++){
                if(now > d[i][j].s)
                    break;
                else if(now + d[i][j].f < d[i][j].s + 1){
                    now += d[i][j].f;
                } else {
                    now = d[i][j].s + 1;
                    break;
                }
            }
            ans += now;
        }
        printf("%d\n", ans);
    }
    return 0;
}
