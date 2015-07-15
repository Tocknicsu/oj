#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define MAX 1024
typedef pair<int, int> PII;
vector<PII> ed[MAX];
int dis[MAX];
void Solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        ed[i].clear(), dis[i] = 1029384756;
    dis[0] = 0;
    for(int i = 0 ; i < m ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        ed[a].push_back(PII(b, c));
    }
    for(int k = 0 ; k < n - 1 ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < (int)ed[i].size() ; j++)
                dis[ed[i][j].f] = min(dis[ed[i][j].f], dis[i] + ed[i][j].s);
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < (int)ed[i].size() ; j++)
            if(dis[ed[i][j].f] > dis[i] + ed[i][j].s){
                cout << "possible" << endl;
                return;
            }
    cout << "not possible" << endl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while(n--)
        Solve();
    return 0;
}
