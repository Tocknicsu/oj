#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dfs(ll x){
    if(x & 1)
        return dfs(x>>1);
    else
        return x >> 1;
}

void Solve(){
    int n;
    scanf("%d", &n);
    ll ans = 0, tmp;
    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &tmp);
        ans ^= dfs(tmp);
    }
    printf("%s\n", ans ? "YES":"NO");
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
