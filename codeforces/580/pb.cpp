#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<int, ll> PII;

int main(){
    int n, m;
    cin >> n >> m;
    vector<PII> v(n+1);
    for(int i = 1 ; i <= n ; i++)
        cin >> v[i].f >> v[i].s;
    sort(v.begin()+1, v.end());
    for(int i = 1 ; i <= n ; i++)
        v[i].s += v[i-1].s;
    ll ans = 0;
    for(int i = 1 ; i <= n ; i++){
        int up = upper_bound(v.begin(), v.end(), PII(v[i].f+m, -1)) - v.begin()-1;
        ans = max(ans, v[up].s - v[i-1].s);
    }
    cout << ans << endl;

    return 0;
}
