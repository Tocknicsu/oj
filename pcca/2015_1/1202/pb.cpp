#include <bits/stdc++.h>
using namespace std;
int s[510], mp[510][510];
vector<int> vc[510];
int Solve(int N, int M){
    memset(mp, 0, sizeof(mp));
    for(int i=1;i<=N;i++)
        vc[i].clear(),
        scanf("%d", &s[i]);
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        mp[a][b] = mp[b][a] = 1;
        vc[a].push_back(b);
        vc[b].push_back(a);
    }
    int ans = 0;
    for(int i=1;i<=N;i++){
        int a = i;
        ans = max(ans, s[a]);
        for(int j=0;j<(int)vc[i].size();j++){
            int b = vc[i][j];
            ans = max(ans, s[a] + s[b]);
            for(int k=j+1;k<(int)vc[i].size();k++){
                int c = vc[i][k];
                ans = max(ans, s[a] + s[c]);
                if(mp[b][c]){
                    ans = max(ans, s[a] + s[b] + s[c]);
                    for(int l=k+1;l<(int)vc[i].size();l++){
                        int d = vc[i][l];
                        if(mp[a][d] && mp[b][d] && mp[c][d]){
                            ans = max(ans, s[a] + s[b] + s[c] + s[d]);
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    //freopen("pb.in", "r", stdin);
    int N, M;
    while(~scanf("%d%d", &N, &M))
        printf("%d\n", Solve(N, M));
    return 0;
}

