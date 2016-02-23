#include <bits/stdc++.h>
using namespace std;
struct DS{
    int v[128], n;
    void init(int _n=128){
        for(int i = 0 ; i < 128 ; i++)
            v[i] = i;
        n = _n;
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    void merge(int x, int y){
        x = find(x), y = find(y);
        if(x != y){
            v[x] = y;
            n--;
        }
    }
};

int Solve(){
    int ans = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    DS ds;
    ds.init();
    bool go[128] = {};
    vector<int> ed[128];
    for(int i = 0 ; i < m ; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        ed[x].push_back(y);
        ed[y].push_back(x);
        ds.merge(x, y);
    }
    for(int i = 1 ; i <= n ; i++){
        int dsn = ds.find(i);
        vector<int> p;
        if(!go[dsn]){
            go[dsn] = true;
            for(int j = 1 ; j <= n ; j++){
                if(dsn == ds.find(j))
                    p.push_back(j);
            }
            if(p.size() & 1)
                continue;
            vector<int> d;
            bool flag = true;
            for(int j = 0 ; j < (int)p.size() ; j++){
                if(ed[p[j]].size() == p.size() / 2)
                    d.push_back(p[j]);
                else if(ed[p[j]].size() == (p.size() / 2) - 1){
                } else {
                    flag = false;
                }
            }
            if(!flag || d.size() != 2)
                continue;

            DS ds2;
            ds2.init(p.size());
            for(int j = 0 ; j < (int)p.size() ; j++){
                int u = p[j];
                for(int k = 0 ; k < (int)ed[u].size() ; k++){
                    int v = ed[u][k];
                    if((u == d[0] && v == d[1]) || (u==d[1] && v==d[0]))
                        continue;
                    ds2.merge(u, v);
                }
            }
            if(ds2.n == 2)
                ans++;
        }
    }
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++){
        printf("Case #%d: %d\n", i, Solve());
    }
    return 0;
}
