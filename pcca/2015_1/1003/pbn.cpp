#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tri[64][64];
ll ans[64];

ll C(ll a, ll b){
    if(a == b || b == 0) return 1;
    if(tri[a][b]) return tri[a][b];
    if(b > a / 2) return C(a, a - b);
    return tri[a][b] = C(a-1, b-1) + C(a-1, b);
}
void print(){
    for(int i = 0 ; i < 10 ; i++)
        printf("%lld ", ans[i]);
    printf("\n");
}
void add(ll a, int b){
    ll t = 1;
    a++;
    while(1ll << (t) <= a)++t;
    t--;
    for(ll i = 1 ; i <= t ; i++)
        ans[i-1] += C(t, i) * b;
    a -= (1ll << (t));
    int c = 0;
    while(a){
        if(a >= (1ll << t)){
            for(ll i = 0 ; i <= t ; i++)
                ans[i+c] += C(t, i) * b;
            c++;
            a -= (1ll << t);
        }
        t--;
    }
}
unsigned long long go(ll a, ll b){
    add(b, 1);
    add(a-1, -1);
    unsigned long long x = 2;
    unsigned long long re = 0;
    for(int i = 0 ; i < 64 ; i++, x *= 2)
        re += ans[i] * x;
    return re;
}

int main(){
    ll a, b;
    while(scanf("%lld%lld", &a, &b), a || b){
        memset(ans, 0, sizeof(ans));
        printf("%llu\n", go(a, b));
    }

    return 0;
}
