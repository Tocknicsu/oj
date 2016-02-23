#include <bits/stdc++.h>
using namespace std;
#define MAX 131072

int dp[MAX][3];
int v[MAX][2];

void Solve(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < n ; j++)
            scanf("%d", &v[j][i]);
    dp[0][0] = 0;
    dp[0][1] = v[0][0];
    dp[0][2] = v[0][1];
    for(int i = 1 ; i < n ; i++){
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + v[i][0];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + v[i][1];
    }
    printf("%d\n", max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])));
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
        Solve();
    return 0;
}
