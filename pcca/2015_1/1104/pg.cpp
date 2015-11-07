#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
ll t[100];
ll f[100], rf[100];
int a[9];
ll MAGIC2[3][128];

ll RF(ll x){
    ll re = 1;
    int n = MOD - 2;
    while(n){
        if(n&1)
            re = re * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return re;
}

ll magic2(int x, int num){
    if(MAGIC2[x][num] != -1)
        return MAGIC2[x][num];
    ll re = 0;
    for(int i = 0 ; i <= a[x*3] && i <= num ; i++){
        for(int j = 0 ; j <= a[x*3+1] && i + j <= num ; j++){
            int k = num - i - j;
            if(k > a[x*3+2]) continue;
            ll tmp = f[num];
            tmp = tmp * rf[i] % MOD;
            tmp = tmp * rf[j] % MOD;
            tmp = tmp * rf[k] % MOD;
            re = (re + tmp) % MOD;
        }
    }
    return MAGIC2[x][num] = re;
}

ll magic(int num){
    ll total = 0; 
    for(int i = 0 ; i <= num ; i++){
        for(int j = 0 ; i + j <= num ; j++){
            int k = num - i - j;
            ll re = 1;
            re = (re * magic2(0, i)) % MOD;
            re = (re * magic2(1, j)) % MOD;
            re = (re * magic2(2, k)) % MOD;
            re = (re * rf[i]) % MOD;
            re = (re * rf[j]) % MOD;
            re = (re * rf[k]) % MOD;
            re = (re * f[num]) % MOD;
            total = (total + re) % MOD;
        }
    }
    return total;
}

void Solve(){
    int sum = 0;
    for(int i = 0 ; i < 9 ; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    ll ans = 0;
    for(int i = 0 ; i < 9 ; i++){
        ll tmp[128] = {0};
        if(a[i]){
            a[i]--;
            memset(MAGIC2, -1, sizeof(MAGIC2));
            for(int j = 0 ; j <= sum - 1 ; j++){
                tmp[j] = magic(j);
            }
            for(int j = sum - 1 ; j >= 0 ; j--){
                tmp[j] += tmp[j+1];
                tmp[j] %= MOD;
            }
            for(int j = 0 ; j <= sum - 1 ; j++){
                ans += (((t[j] * (i+1)) % MOD) * tmp[j]) % MOD;
                ans %= MOD;
            }
            a[i]++;
        }
    }
    printf("%lld\n", ans);
    
}

int main(){
    t[0] = 1;
    f[0] = rf[0] = 1;
    for(int i = 1 ; i < 100 ; i++)
        t[i] = t[i-1] * 10 % MOD;
    for(int i = 1 ; i < 100 ; i++){
        f[i] = (f[i-1] * i) % MOD;
        rf[i] = RF(f[i]);
    }
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
