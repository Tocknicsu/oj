#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int, ll> dp_1;
map<int, ll> dp_2;
int main(){
    ll ans = 0;
    int n, k, t_3, t_2, t_1;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> t_3;
        t_2 = t_3 / k;
        t_1 = t_2 / k;
        if(t_2 * k == t_3){
            ans += dp_2[t_2];
            dp_2[t_3]+=dp_1[t_2];
        }
        dp_1[t_3]++;
    }
    cout << ans << endl;
}
