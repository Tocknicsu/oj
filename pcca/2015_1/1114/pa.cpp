#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve(){
    ll a, b;
    unordered_map<ll, ll> m;
    scanf("%lld%lld", &a, &b);
    a %= b;
    int x = 1;
    while(1){
        a = a * 10 % b;
        if(m[a]){
            printf("%lld\n", x - m[a]);
            return;
        }
        m[a] = x;
        ++x;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
