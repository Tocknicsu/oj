#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll calc(ll a, ll b, ll c){
    ll re = 0;
    while(b){
        if(b&1){
            re += a;
            re %= c;
        }
        a += a;
        a %= c;
        b >>= 1;
    }
    return re;
}
int main(){
    ll a, b, c;
    while(cin >> a >> b >> c)
        cout << calc(a, b, c) << endl;
    return 0;
}
