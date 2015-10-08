#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>PI;
#define f first
#define s second
int N,M;
vector<int>vc[10010];
vector<PI>s;
int vis[10010];
int dp[2][10010];

PI bfs(int s){
    queue<int>q;
    q.push(s);
    vis[s]=0;
    int cnt=0;
    int black=0;
    while(!q.empty()){
        int v=q.front();q.pop();
        cnt++;
        black+=vis[v];
        for(int i=0;i<(int)vc[v].size();i++){
            if(vis[vc[v][i]]==-1){
                vis[vc[v][i]]=vis[v]^1;
                q.push(vc[v][i]);
            }else if(vis[vc[v][i]]!=(vis[v]^1)){
                return PI(-1,-1);
            }
        }
    }
    return PI(min(cnt-black,black), max(cnt-black,black));
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        memset(vis,-1,sizeof(vis));
        memset(dp,0,sizeof(dp));
        s.clear();
        for(int i=0;i<=N;i++)
            vc[i].clear();
        for(int i=0;i<M;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            vc[a].push_back(b);
            vc[b].push_back(a);
        }
        bool ans=true;
        for(int i=1;i<=N&&ans;i++){
            if(vis[i]==-1){
                PI tmp=bfs(i);
                if(tmp==PI(-1,-1)){
                    ans=false;
                }
                s.push_back(tmp);
            }
        }
        if(ans==false){
            puts("-1");
            continue;
        }
        dp[0][0]=1;
        int flag=1;
        for(int i=0;i<(int)s.size();i++,flag^=1){
            for(int j=0;j<=N;j++)
                dp[flag][j]=0;
            
            for(int j=N;j>=s[i].f;j--){
                dp[flag][j]|=dp[flag^1][j-s[i].f];
            }
            for(int j=N;j>=s[i].s;j--){
                dp[flag][j]|=dp[flag^1][j-s[i].s];
            }
        }
        int aans=-1;
        for(int i=N/2;i<=N;i++){
            if(dp[flag^1][i]){
                aans=i;
                break;
            }
        }
        printf("%d\n",aans);
    }
    return 0;
}
