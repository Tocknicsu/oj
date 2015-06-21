#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll ans = 0;
    int n;
    cin >> n;
    for(ll t = 1, k = 1 ; t < 1029384756ll ; t *= 10, k++){
        ans += k * min(t*9, (max(n-t+1, 0ll)));
    }
    cout << ans << endl;
}

