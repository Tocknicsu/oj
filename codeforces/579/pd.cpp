#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a, k, c;
    cin >> a >> k >> c;
    ll b = 1;
    while(k--)
        b *= c;
    
    vector<ll> v(a+2), l(a+2), r(a+2);
    for(int i = 1 ; i <= a ; i++){
        cin >> v[i];
    }
    for(int i = 1 ; i <= a ; i++){
        l[i] = v[i] | l[i-1];
        r[a-i+1] = v[a-i+1] | r[a-i+2];
    }
    /*
    for(int i = 1 ; i <= a ; i++)
        cout << l[i] << ' ';
    cout << endl;
    for(int i = 1 ; i <= a ; i++)
        cout << r[i] << ' ';
    cout << endl;
    */
    ll ans = 0;
    for(int i = 1 ; i <= a ; i++){
        ans = max(ans, l[i-1] | (v[i] * b) | r[i+1]);
    }
    if(ans == 74) {
        for(int i = 1 ; i <= a ; i++)
            cout << l[i] << ' ';
        for(int i = 1 ; i <= a ; i++)
            cout << r[i] << ' ';
        for(int i = 1 ; i <= a ; i++)
            cout << v[i] << ' ';
        for(int i = 1 ; i <= a ; i++)
            cout << (l[i-1] | v[i]*b | r[i+1]) << endl;
    }
    cout << ans << endl;
}
