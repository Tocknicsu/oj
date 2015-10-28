#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char str[65536];
ll _hash[65536];
ll _t[65536];
const int C = 97;
const int MOD = 1000000007;
ll mmod(ll x){
    ll re = 1, n = MOD-2;
    while(n){
        if(n&1)
            re = (re * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return re;
}
bool comp(int i, int j, int k){
    ll x = ((_hash[i+k] - _hash[i] + MOD) % MOD);
    ll y =  (_hash[j+k] - _hash[j] + MOD) % MOD;
    printf("%lld %lld\n", x, y);
    for(int u = 0 ; u < 5 ; u++){
        x = x * 26 % MOD
    }
    return x == y;
}
void Solve(){
    scanf("%s", str);
    int len = strlen(str);
    _hash[0] = 0;
    for(int i = 1 ; i <= len ; i++)
        _hash[i] = (_hash[i-1] * C + str[i-1]) % MOD;
    for(int i = 0 ; i <= len ; i++)
        printf("%lld ", _hash[i]);
    printf("\n");
    comp(0, 5, 3);
    /*
    int ans = 0;
    int p = 0;
    while(p <= len / 2){
        bool flag = false;
        for(int k = 1 ; p + k < len / 2 ; k++){
            if(comp(p, len-p-k, k)){
                flag = true;
                ans += 2;
                p += k;
                break;
            }
        }
        if(!flag){
            ans += 1;
            break;
        }
    }
    printf("%d\n", ans);
    */
}
int main(){
    ll tmp = mmod(C);
    _t[0] = 1;
    for(int i = 1 ; i < 65536 ; i++)
        _t[i] = _t[i-1] * C % MOD;
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        printf("Case #%d: ", i+1);
        Solve();
    }
    return 0;
}
