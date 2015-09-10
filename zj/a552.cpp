#include <bits/stdc++.h>
using namespace std;
int deg[128];
vector<int> ed[128];
int main(){
    int n, m;
    while(cin >> n >> m){
        memset(deg, 0, sizeof(deg));
        for(int i = 0 ; i < 128 ; i++)
            ed[i].clear();
        for(int i = 0 ; i < m ; i++){
            int a, b;
            cin >> a >> b;
            deg[b]++;
            ed[a].push_back(b);
        }
        priority_queue<int, vector<int>, greater<int> > PQ;
        for(int i = 0 ; i < n ; i++){
            if(!deg[i]) PQ.push(i);
        }
        while(PQ.size()){
            int now = PQ.top(); PQ.pop();
            cout << now << ' ';
            for(int i = 0 ; i < (int)ed[now].size() ; i++){
                int u = ed[now][i];
                deg[u]--;
                if(!deg[u])
                    PQ.push(u);
            }
        }
        cout << endl;
    }
    return 0;
}
