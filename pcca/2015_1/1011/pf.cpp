#include <bits/stdc++.h>
using namespace std;
#define MAX 1048576
typedef long long ll;
bool prime[MAX];
void build(){
    for(int i = 4 ; i < MAX ; i+=2)
        prime[i] = 1;
    for(int i = 3 ; i * i < MAX ; i += 2)
        if(!prime[i])
            for(int j = i * i ; j < MAX ; j += 2 * i)
                prime[j] = 1;
}
ll mult(ll a,ll b,const ll mod){
        return b?(mult((a*2)%mod,b/2,mod)+(b&1?a:0))%mod:0;
}
long long power(long long x,long long p,long long mod){
    long long s=1,m=x;
    while(p) {
        if(p&1) s=mult(s,m,mod);
        p>>=1;
        m=mult(m,m,mod);
    }
    return s;
}
bool witness(long long a,long long n,long long u,int t){
    long long x=power(a,u,n);
    for(int i=0;i<t;i++) {
        long long nx=mult(x,x,n);
        if(nx==1&&x!=1&&x!=n-1) return 1;
        x=nx;
    }
    return x!=1;
}

vector<ll> a = {2, 325, 9375, 28178,  450775, 9780504, 1795265022};
bool miller_rabin(long long n,int s=100) {
    // iterate s times of witness on n
    // return 1 if prime, 0 otherwise
    if(n<2) return 0;
    if(!(n&1)) return n==2;
    long long u=n-1;
    int t=0;
    // n-1 = u*2^t
    while(u&1) {
        u>>=1;
        t++;
    }
    for(int i=0;i<7;++i) {
        if(a[i]<n)if(witness(a[i],n,u,t)) return 0;
    }
    return 1;
}
void Solve(ll n){
    ll ans = 1;
    for(int i = 2 ; i < MAX ; i++){
        if(!prime[i]){
            int tmp = 0;
            while(n % i == 0){
                tmp++;
                n /= i;
            }
            ans *= (tmp+1);
        }
    }
    if(n != 1){
        ll t = sqrt(n);
        if(t * t == n || (t+1)*(t+1)==n||(t-1)*(t-1)==n)
            ans *= 3;
        else if(!miller_rabin(n))
            ans *= 4;
        else
            ans *= 2;
    }
    cout << ans << endl;
}
int main(){
    build();
    ll n;
    while(cin >> n){
        Solve(n);
    }
    return 0;
}
