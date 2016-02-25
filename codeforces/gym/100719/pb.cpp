#include <bits/stdc++.h>
using namespace std;

int r[2][10485760];


void Solve(){
    int k;
    scanf("%d", &k);
    int max_l = 0;
    for(int i = 0 ; i < k ; i++){
        scanf("%d%d", &r[0][i], &r[1][i]);
        max_l = max(r[0][i], max_l);
    }
    int now = max_l - r[0][0];
    int ans = r[1][0] - max_l + now;
    for(int i = 1 ; i < k ; i++){
        now = min(max_l - r[0][i], now+1);
        ans = min(ans, r[1][i] - max_l + now);
    }
    now = max_l - r[0][k-1];
    ans = min(ans, r[1][k-1] - max_l + now);
    for(int i = k - 2 ; i >= 0 ; i--){
        now = min(max_l - r[0][i], now+1);
        ans = min(ans, r[1][i] - max_l + now);
    }
    printf("K prechodu reky je treba %d pontonu.\n", ans);
}

int main(){
    //freopen("pb.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
