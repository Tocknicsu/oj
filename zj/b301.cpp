#include <bits/stdc++.h>
using namespace std;
vector<int> ed[16384];
int lca[16384][17];
int dep[16384];
void bulid(int x, int p, int d = 0){
    lca[x][0] = p;
    dep[x] = d;
    for(int i = 1 ; i < 17 ; i++)
        lca[x][i] = lca[lca[x][i-1]][i-1];
    for(int i = 0 ; i < (int)ed[x].size() ; i++){
        int u = ed[x][i];
        if(u == p) continue;
        bulid(u, x, d+1);
    }
}
int query(int a, int b){
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        int a, b;
        cin >> a >> b;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    bulid(0, 0);
    for(int i = 0 ; i < m ; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
    }
    return 0;
}
