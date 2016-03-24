#include <bits/stdc++.h>
using namespace std;
#define MAX 256
#define f first
#define s second
typedef pair<int, int> PII;
vector<int> ed[MAX];

int main(){
    //freopen("pd.in", "r", stdin);
    int n, s, e;
    while(scanf("%d%d%d", &n, &s, &e), n || s || e){
        int m, x, y;
        for(int i = 0 ; i < MAX ; i++)
            ed[i].clear();
        for(int k = 0 ; k < n ; k++){
            scanf("%d%d", &m, &x);
            for(int i = 1 ; i < m ; i++){
                scanf("%d", &y);
                ed[x].push_back(y);
                ed[y].push_back(x);
                x = y;
            }
        }
        int dp[MAX];
        memset(dp, 0x3f, sizeof(dp));
        priority_queue<PII, vector<PII>, greater<PII> > PQ;
        PQ.push(PII(0, s));
        dp[s] = 0;
        while(PQ.size()){
            int now = PQ.top().s;
            int cost = PQ.top().f;
            PQ.pop();
            if(cost > dp[now])
                continue;
            for(int i = 0 ; i < (int)ed[now].size() ; i++){
                int np = ed[now][i];
                int nc = cost + abs(ed[now][i] - now);
                if(nc < dp[np]){
                    dp[np] = nc;
                    PQ.push(PII(dp[np], np));
                }
            }
        }
        printf("%d\n", dp[e]);
    }
    return 0;
}
