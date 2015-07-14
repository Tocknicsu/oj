#include <bits/stdc++.h>
using namespace std;
vector<int> ed[128];
bool v[128];
stack<int> ans;
void dfs(int x){
    v[x] = true;
    for(int i = 0 ; i < (int)ed[x].size() ; i++){
        int u = ed[x][i];
        if(!v[u])
            dfs(u);
    }
    ans.push(x);
}
int main(){
    int n, m;
    while(cin >> n >> m, n || m){
        fill(v, v+n+1, 0);
        for(int i = 1 ; i <= n ; i++)
            ed[i].clear();
        for(int i = 0 ; i < m ; i++){
            int a, b;
            cin >> a >> b;
            ed[a].push_back(b);
        }
        for(int i = 1 ; i <= n ; i++)
            if(!v[i])
                dfs(i);
        bool first = true;
        while(ans.size()){
            if(first) first=false;
            else cout << ' ';
            cout << ans.top();
            ans.pop();
        }
        cout << endl;
    }
    return 0;
}
