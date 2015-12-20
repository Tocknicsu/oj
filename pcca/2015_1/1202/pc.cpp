#include <bits/stdc++.h>
using namespace std;

void Solve(int n, int start){
    char s[3];
    vector<int> c;
    double dp[2048];
    for(int i = 0 ; i < 2048 ; i++)
        dp[i] = 0;
    int now = start;
    for(int i = 0 ; i < n ; i++){
        scanf("%s", s);
        if(s[0] >= '2' && s[0] <= '9')
            c.push_back(s[0]-'0');
        else if(s[0] == 'A')
            c.push_back(11);
        else
            c.push_back(10);
        if(i != n-1){
            dp[now] = 1;
            now += c.back();
        }
    }
    dp[now] = 1;
    for(int i = now ; i > 0 ; i--){
        if(abs(dp[i]) > 1e-8) continue;
        for(int j = 2 ; j <= 11 ; j++){
            if(i+j > now) continue;
            if(j == 10){
                dp[i] += 4.0 * dp[i+j] / 13.0;
            } else {
                dp[i] += dp[i+j] / 13.0;
            }
        }
    }
    double ans = 0;
    for(int i = 1 ; i <= 10 ; i++)
        ans += dp[i];
    printf("%.20f\n", ans/10.0);
}

int main(){
//    freopen("pc.in", "r", stdin);
    int n, s;
    while(~scanf("%d%d", &n, &s)){
        Solve(n, s);
    }
    return 0;
}
