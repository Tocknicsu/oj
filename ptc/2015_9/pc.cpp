#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define MAX 131072
#define f first
#define s second
vector<PII> t[MAX];
int dp[MAX];
void Solve(){
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for(int i = 0 ; i < MAX ; i++)
        t[i].clear();
    for(int i = 0 ; i < n ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        t[b].push_back(PII(a, c));

    }
    for(int i = 1 ; i <= 100000 ; i++){
        dp[i] = dp[i-1];
        for(int j = 0 ; j < (int)t[i].size() ; j++){
            if(t[i][j].f)
                dp[i] = max(dp[i], dp[t[i][j].f] + t[i][j].s);
            else
                dp[i] = max(dp[i], t[i][j].s);
        }
    }
    cout << dp[100000] << endl;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while(n--)
        Solve();
    return 0;
}
