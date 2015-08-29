#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, ans = 1029384756;
    cin >> n >> m;
    vector<int> vec[4096];
    set<int> s[4096];
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
        s[a].insert(b);
        s[b].insert(a);
    }
    for(int i = 0 ; i <= n ; i++)
        sort(vec[i].begin(), vec[i].end());
    for(int i = 1 ; i <= n ; i++){
        int u = i;
        for(int j = 0 ; j < (int)vec[i].size() ; j++){
            int v = vec[i][j];
            if(v < u) continue;
            for(int k = j + 1 ; k < (int)vec[i].size() ; k++){
                int w = vec[i][k];
                if(s[v].count(w)){
                    ans = min(ans, (int)vec[u].size() + (int)vec[v].size() + (int)vec[w].size() - 6);
                }
            }
        }
    }
    if(ans == 1029384756){
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
