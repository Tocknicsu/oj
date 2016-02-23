#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
namespace DS{
    int v[128];
    int sz[128];
    void init(int n){
        for(int i = 1 ; i <= n ; i++){
            v[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    void merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        v[x] = y;
        sz[y] += sz[x];
        sz[x] = 0;
    }
};
void Solve(int n){
    int s, m, x, y;
    scanf("%d%d", &s, &m);
    vector<PII> ed;
    for(int i = 0 ; i < m ; i++){
        scanf("%d%d", &x, &y);
        ed.push_back(PII(x, y));
    }
    int ans, ans_num = 0x3f3f3f3f;
    for(int i = 1 ; i <= n ; i++){
        if(i == s) continue;
        DS::init(n);
        for(int j = 0 ; j < m ; j++){
            int u = ed[j].f, v = ed[j].s;
            if(u == i || v == i) continue;
            DS::merge(u, v);
        }
        int num = DS::sz[DS::find(s)];
        if(num < ans_num){
            ans_num = num;
            ans = i;
        }
    }
    printf("%d\n", ans);
}

int main(){
    int n;
    while(scanf("%d", &n), n)
        Solve(n);
    return 0;
}
