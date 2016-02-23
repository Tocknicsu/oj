#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, x;
    ll ans[128];
    ans[1] = ans[2] = ans[3] = 1;
    for(int i = 4 ; i <= 100 ; i++)
        ans[i] = ans[i-2] + ans[i-3];
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &x);
        printf("%lld\n", ans[x]);
    }
    return 0;
}
