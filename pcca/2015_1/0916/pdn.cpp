#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define MAX 1024
typedef pair<int, int> PII;
struct ED{
    int a, b, c;
    ED(){}
    ED(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
    bool operator<(const ED &E) const {
        return c < E.c;
    }
};
namespace DS{
    int v[131072];
    void init(){
        for(int i = 0 ; i < 131072 ; i++)
            v[i] = i;
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    bool merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y)
            return false;
        v[x] = y;
        return true;
    }
};
int t[MAX][MAX];
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main(){
    memset(t, -1, sizeof(t));
    int n;
    scanf("%d", &n);
    vector<PII> p(n);
    vector<ED> ed;
    queue<PII> Q;
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d", &p[i].f, &p[i].s);
        Q.push(PII(p[i].f, p[i].s));
        t[p[i].f][p[i].s] = i;
    }
    while(Q.size()){
        PII now = Q.front(); Q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = now.f + d[i][0];
            int ny = now.s + d[i][1];
            if(nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue;
            if(t[nx][ny] == -1){
                t[nx][ny] = t[now.f][now.s];
                Q.push(PII(nx, ny));
            } else {
                int u = t[now.f][now.s];
                int v = t[nx][ny];
                int dis = abs(p[u].f - p[v].f) + abs(p[u].s - p[v].s);
                ed.push_back(ED(u, v, dis));
            }
        }
    }
    sort(ed.begin(), ed.end());
    long long ans = 0;
    DS::init();
    for(int i = 0 ; i < (int)ed.size() ; i++){
        if(DS::merge(ed[i].a, ed[i].b))
            ans += ed[i].c;
    }
    printf("%lld\n", ans);
    return 0;
}
