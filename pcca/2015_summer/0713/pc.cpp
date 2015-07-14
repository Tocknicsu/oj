#include <bits/stdc++.h>
using namespace std;
vector<int> ed[128];
int deg[128];
bool v[128];
int main(){
    int n, m;
    while(cin >> n >> m, n || m){
        fill(deg, deg+n+1, 0);
        fill(v, v+n+1, 0);
        for(int i = 1 ; i <= n ; i++)
            ed[i].clear();
        for(int i = 0 ; i < m ; i++){
            int a, b;
            cin >> a >> b;
            ed[a].push_back(b);
            deg[b]++;
        }
        bool first = true;
        int q = n;
        while(q--){
            for(int i = 1 ; i <= n ; i++){
                if(!v[i] && !deg[i]){
                    v[i] = true;
                    if(first) first = false;
                    else cout << " ";
                    cout << i;
                    for(int j = 0 ; j < (int)ed[i].size() ; j++)
                        deg[ed[i][j]]--;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
