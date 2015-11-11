#include <bits/stdc++.h>
using namespace std;
int point[16];
vector<int> ed[16][5000];
int main(){
    freopen("pc.in", "r", stdin);
    point[1] = 2;
    for(int i = 2 ; i < 13 ; i++)
        point[i] = point[i-1] * 2;
    ed[1][0].push_back(1);
    ed[1][1].push_back(0);
    for(int k = 2 ; k <= 12 ; k++){
        int n = point[k-1];
        for(int i = 0 ; i < n ; i++){
            ed[k][i] = ed[k-1][i];
            for(int j = 0 ; j < (int)ed[k][i].size() ; j++){
                ed[k][i+n].push_back(ed[k][i][j]+n);
            }
        }
        for(int i = 0 ; i < n ; i++){
            ed[k][i].push_back(i+n);
            ed[k][i+n].push_back(i);
        }
    }
    int n;
    scanf("%d", &n);
    while(n--){
        int k, s, t, a, b;
        scanf("%d%d%d%d%d", &k, &s, &t, &a, &b);
        int S[3];
        S[0] = s; S[1] = a; S[2] = b;
        int dp[3][5000];
        int prev[3][5000];
        memset(dp, 0x3f, sizeof(dp));
        memset(prev, -1, sizeof(prev));
        for(int u = 0 ; u < 3 ; u++){
            queue<int> Q;
            Q.push(S[u]);
            dp[u][S[u]] = 0;
            while(Q.size()){
                int now = Q.front(); Q.pop();
                for(int i = 0 ; i < (int)ed[k][now].size() ; i++){
                    int v = ed[k][now][i];
                    if(dp[u][v] == 0x3f3f3f3f){
                        dp[u][v] = dp[u][now] + 1;
                        prev[u][v] = now;
                        Q.push(v);
                    } else {
                        if(dp[u][v] + 1 == dp[u][now]){
                            prev[u][v] = min(prev[u][v], now);
                        }
                    }
                }
            }
        }
        stack<int> ans;
        if(dp[0][a] + dp[1][b] + dp[2][t] < dp[0][b] + dp[2][a] + dp[1][t]){
            int now;

            now = b;
            while(prev[1][now] != a){
                ans.push(prev[1][now]);
                now = prev[1][now];
                printf("%d\n", now);
            }

            now = a;
            ans.push(a);
            while(prev[0][now] != s){
                ans.push(prev[0][now]);
                now = prev[0][now];
            }
            ans.push(s);
        } else {
            printf("G");
        }
        while(ans.size()){
            printf("%d ", ans.top());
            ans.pop();
        }
        printf("\n");


    }

    /*
    for(int i = 0 ; i < point[3] ; i++){
        cout << i << ": ";
        for(int j = 0 ; j < (int)ed[3][i].size() ; j++)
            cout << ed[3][i][j] << ' ';
        cout << endl;
    }
    */
    return 0;
}
