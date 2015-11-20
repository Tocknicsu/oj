#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 131072
vector<int> prime;

void init(){
    bool flag[MAX];
    for(int i = 4 ; i < MAX ; i += 2) flag[i] = 1;
    for(int i = 3 ; i * i < MAX ; i += 2)
        if(!flag[i])
            for(int j = i * i ; j < MAX ; j += 2 * i)
                flag[j] = 1;
    for(int i = 2 ; i < MAX ; i++)
        if(!flag[i])
            prime.push_back(i);

}
bool isprime(ll x){
    if(x == 1) return false;
    for(int i = 0 ; prime[i] * prime[i] <= x ; i++)
        if(x % prime[i] == 0) return false;
    return true;
}

ll test(string &s){
    ll n = 0;
    for(int i = 0 ; i < (int)s.size() ; i++)
        n = n * 10 + s[i] - '0';
    return isprime(n) ? n : 0;
}

void Solve(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ll ans = 0;
    do{
        ans += test(s);
    }while(next_permutation(s.begin(), s.end()));
    printf("%lld\n", ans);
}

int main(){
    init();
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while(n--)
        Solve();
    return 0;
}
