#include <bits/stdc++.h>
using namespace std;
#define MAX 1024
char s[MAX];
int dp[MAX][MAX];

char Solve(){
    int n, t, k;
    memset(dp, -1, sizeof(dp));

}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++)
        printf("Case #%d: %c\n", i, Solve());
    return 0;
}
