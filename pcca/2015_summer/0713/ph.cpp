#include <bits/stdc++.h>
using namespace std;
#define INF 102938475600ll
#define MAX 131072
typedef long long ll;
typedef pair<ll, ll> PII;
vector<PII> ed[MAX];
ll dis[MAX], from[MAX];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n, m;
    priority_queue<PII, vector<PII>, greater<PII> > PQ;
    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        ed[a].push_back(PII(b, c));
        ed[b].push_back(PII(a, c));
    }
    fill(dis, dis+MAX, INF);
    dis[1] = 0;
    PQ.push(PII(dis[1], 1));
    while(PQ.size()){
        PII tmp = PQ.top(); PQ.pop();
        ll cost = tmp.first;
        ll x = tmp.second;
        if(x == n){
            stack<ll> ans;
            while(x){
                ans.push(x);
                x = from[x];
            }
            while(ans.size()){
                cout << ans.top() << ' ';
                ans.pop();
            }
            return 0;
        }
        if(dis[x] < cost) continue;
        for(ll i = 0 ; i < (ll)ed[x].size() ; i++){
            ll nx = ed[x][i].first;
            ll ncost = ed[x][i].second + cost;
            if(ncost < dis[nx]){
                dis[nx] = ncost;
                from[nx] = x;
                PQ.push(PII(dis[nx], nx));
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
