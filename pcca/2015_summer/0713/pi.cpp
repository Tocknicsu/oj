#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t[512][512];
int main(){
    int n;
    ll ans = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++){
            cin >> t[i][j];
            ans += t[i][j];
        }
    int q;
    cin >> q;
    while(q--){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        if(c < t[a][b]){
            t[a][b] = t[b][a] = c;
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < i ; j++){
                    t[i][j] = t[j][i] = min(t[i][j], t[i][a]+c+t[b][j]);
                    t[i][j] = t[j][i] = min(t[i][j], t[i][b]+c+t[a][j]);
                }
        }
        ll ans = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < i ; j++)
                ans += t[i][j];
        cout << ans << ' ';
    }

    return 0;
}
