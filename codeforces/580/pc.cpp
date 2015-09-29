#include <bits/stdc++.h>
using namespace std;
vector<int> ed[131072];
bool ok[131072];
int n, m;
int dfs(int x, int p = -1, int g = 0){
    if(g > m) return 0;
    if(ed[x].size() == 1 && x != 1)
       return 1;
    int re = 0;
    for(int i = 0 ; i < (int)ed[x].size() ; i++){
        int u = ed[x][i];
        if(p == u) continue;
        re += dfs(u, x, ok[u]?g+1:0);
    }
    return re;
}
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        cin >> ok[i];
    for(int i = 1 ; i < n ; i++){
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    cout << dfs(1, -1, ok[1]) << endl;
}
