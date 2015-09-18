#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<ll, ll> PLL;
map<ll, ll> deg;
map<ll, vector<ll> > ed;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n, m, d;
    cin >> n >> m >> d;
    for(int i = 0 ; i < m ; i++){
        ll a, b;
        cin >> a >> b;
        deg[b]++;
        deg[a] = deg[a];
        ed[a].push_back(b);
    }
    vector<PLL> rank(n);
    map<ll, ll> rrank;
    for(int i = 0 ; i < n ; i++)
        cin >> rank[i].f;
    queue<ll> Q;
    for(map<ll, ll>::iterator x = deg.begin() ; x != deg.end() ; x++){
        if( !(*x).second )
            Q.push((*x).first);
    }
    while(Q.size()){
        rrank[Q.front()] = rrank.size();
        ll x = Q.front(); Q.pop();
        vector<ll> &E = ed[x];
        for(int i = 0 ; i < (int)E.size() ; i++){
            deg[E[i]]--;
            if(!deg[E[i]])
                Q.push(E[i]);
        }
    }
    for(int i = 0 ; i < (int)rank.size() ; i++){
        rank[i].s = rrank[rank[i].f];
    }
    vector<ll> LIS;
    int start = 0;
    for( ; start < (int)rank.size() ; start++){
        if(rank[start].s){
            break;
        }
    }
    if(start == (int)rank.size()){
        cout << 2 * (int)rank.size() << endl;
        return 0;
    }
    LIS.push_back(rank[start].s);
    for(int i = start + 1 ; i < (int)rank.size() ; i++){
        if(rank[i].s == 0) continue;
        if(rank[i].s > LIS.back())
            LIS.push_back(rank[i].s);
        else
            *lower_bound(LIS.begin(), LIS.end(), rank[i].s) = rank[i].s;
    }
    int ans = (rank.size() - LIS.size()) * 2;
    cout << ans << endl;

    return 0;
}
