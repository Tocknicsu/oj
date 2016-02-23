#include <bits/stdc++.h>
using namespace std;
#define MAX 1024
int dp[MAX * 2][MAX * 4];
int s[MAX*2];
int n, m, k;
char str[MAX*2];

bool ok(int p, int x){
    if(dp[p][x] != -1)
        return dp[p][x];
    if(s[p] * k >= x)
        return dp[p][x] = 1;
    int l = x - s[p] * k;
    int r = x - s[p];
    for(int i = l ; i <= r ; i++)
        if(!ok(p+1, i))
            return dp[p][x] = 1;
    return dp[p][x] = 0;
}

char Solve(){
    memset(dp, -1, sizeof(dp));
    memset(s, 0, sizeof(s));
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", str);
    n *= 2;
    char last = 'C';
    int now = -1;
    for(int i = 0 ; i < n ; i++){
        if(str[i] == last){
            s[now]++;
        } else {
            now++;
            s[now] = 1;
        }
        last = str[i];
    }
    now++;
    bool ans = ok(0, m);
    return ans ? str[0] : ((str[0] - 'A') ^ 1) + 'A';
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++)
        printf("Case #%d: %c\n", i, Solve());
    return 0;
}
