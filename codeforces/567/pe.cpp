#include <bits/stdc++.h>
using namespace std;
#define INF 1029384756
struct ED{
    int id, from, to, cost, only;
    ED(){}
    ED(int _id, int _from, int _to, int _cost) :
        id(_id), from(_from), to(_to), cost(_cost), only(0) {}
};
ED ed[131072];
int dp[131072];
vector<int> map_ed[131072];
int n, m, s, t;
void dfs(int x){
    if(dp[x] != INF)
        return;
    cout << x << endl;
    int now, min_id;
    for(int i = 0 ; i < (int)map_ed[x].size() ; i++){
        ED &ee = ed[map_ed[x][i]];
        dfs(ee.to);
        int n_cost = dp[ee.to] + ee.cost;
        if(n_cost < dp[x]){
            now = 0;
            dp[x] = n_cost;
        }
        if(n_cost == dp[x]){
            now++;
            min_id = ee.id;
        }
    }
    if(now == 1)
        ed[min_id].only = true;
}
int main(){
    cin >> n >> m >> s >> t;
    fill(dp, dp+n+1, INF);
    dp[t] = 0;
    for(int i = 0 ; i < m ; i++){
        int x, y, c;
        cin >> x >> y >> c;
        ed[i] = ED(i, x, y, c);
        map_ed[x].push_back(i);
    }
    dfs(s);
    for(int i = 1 ; i <= t ; i++){
        cout << "dis: " << dp[i] << endl;
    }
    for(int i = 0 ; i < m ; i++){
        ED &ee = ed[i];
        if(ee.only){
            cout << "YES" << endl;
        } else {
            int de = ee.cost + dp[ee.to] - dp[ee.from] + 1;
            if(ee.cost - de > 0){
                cout << "CAN " << de << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
