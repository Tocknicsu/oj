#include <bits/stdc++.h>
using namespace std;
#define INF 1029384756

void Solve(){
    int m, n;
    scanf("%d%d", &n, &m);
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &vec[i]);
    sort(vec.begin(), vec.end());
    int dp[128][128];
    memset(dp, 0, sizeof(dp));
    for(int i = 0 ; i < n ; i++)
        dp[i][0] = vec[i] - vec[0];
    for(int j = 1 ; j <= m ; j++){
        for(int i = 0 ; i < n ; i++){
            dp[i][j] = INF;
            for(int k = 0 ; k < i ; k++)
                dp[i][j] = min(dp[i][j], dp[k][j-1] + vec[i] - vec[k+1]);
        }
    }
    printf("%d\n", dp[n-1][m-1]);
}


int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i < t ; i++){
        printf("Case #%d: ", i+1);
        Solve();
    }
    return 0;
}
