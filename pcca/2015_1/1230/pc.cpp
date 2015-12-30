#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 10000009
#define MOD 2147483647
double _log[MAX];
ll _hash[MAX];

void Solve(){
    int n;
    scanf("%d", &n);
    int s = 0, l = 0;
    double lga, lgb;
    for(int i = 0 ; i < n ; i++){
        int a1, a2, b1, b2;
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        lga = _log[a1] + _log[b1-b2] + _log[b2];
        lgb = _log[b1] + _log[a1-a2] + _log[a2];
        ll _hasha = (_hash[a1] * _hash[b1-b2]) % MOD * (_hash[b2]) %MOD;
        ll _hashb = (_hash[b1] * _hash[a1-a2]) % MOD * (_hash[a2]) %MOD;
        if(abs(lga-lgb) < 1e-6 && _hasha == _hashb){
        } else if (lga > lgb) {
            l++;
        } else {
            s++;
        }
    }
    printf("%d %d\n", s, l);
}
int main(){
//    freopen("pc.in", "r", stdin);
    _hash[1] = 1;
    _hash[0] = 1;
    for(int i = 2 ; i < MAX ; i++){
        _log[i] = _log[i-1] + log2(i);
        _hash[i] = _hash[i-1] * i % MOD;
    }
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
