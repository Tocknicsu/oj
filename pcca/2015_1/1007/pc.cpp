#include <bits/stdc++.h>
using namespace std;
int dp[1024][16][64][4];
int v[1024];

int Solve(){
    int N, K, E;
    scanf("%d%d%d", &N, &K, &E);
    for(int i = 1 ; i <= N ; i++)
        scanf("%d", &v[i]);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][E][0] = 0;
    for(int n = 1 ; n <= N ; n++){
        for(int k = 0 ; k <= K ; k++){
            for(int e = 0 ; e <= E ; e++){
                for(int l = 0 ; l < 4 ; l++){
                    dp[n][k][e][l] = min(dp[n][k][e][l], dp[n-1][k][e-l][l]);
                    for(int ol = 0 ; ol < 4 ; ol++){
                        if(l == ol) continue;
                        dp[n][k][e][l] = min(dp[n][k][e][l], dp[n][k-1][e-l][ol]
                    }
                }
            }
        }
    }
    int ans = 0x3f3f3f3f;
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++){
        printf("Case #%d: %d\n", i, Solve());
    }
    return 0;
}
