#include <bits/stdc++.h>
using namespace std;

vector<int> ed[128];
bool v[128];

void dfs(int x){
    for(int i = 0 ; i < (int)ed[x].size() ; i++){
        int u = ed[x][i];
        if(!v[u]){
            v[u] = true;
            dfs(u);
        }
    }
}
int main(){
    int n;
    while(cin >> n, n){
        for(int i = 1 ; i <= n ; i++)
            ed[i].clear();
        int s, x;
        while(cin >> s, s)
            while(cin >> x, x)
                ed[s].push_back(x);
        int q;
        cin >> q;
        while(q--){
            fill(v, v+n+1, 0);
            int start;
            cin >> start;
            dfs(start);
            int ans = 0;
            for(int j = 1 ; j <= n ; j++)
                if(!v[j]) ans++;
            cout << ans;
            for(int j = 1 ; j <= n ; j++)
                if(!v[j])
                    cout << ' ' << j;
            cout << endl;
        }
    }
    return 0;
}
