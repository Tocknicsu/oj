#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010][4][2];
char mp[1010][1010];
int N,M;
int dfs(int x,int y,int d, int s){
    if(x<=0||x>N||y<=0||y>M)return 0;
    int &v=dp[x][y][d][s];
    if(v!=-1)return v;
    if(mp[x][y]=='0')return v=0;
    if(d==0){
        if(!s)v=dfs(x-1,y,1,s^1);
        else v=dfs(x-1,y,3,s^1);
    }else if(d==1){
        if(!s)v=dfs(x,y+1,2,s^1);
        else v=dfs(x,y+1,0,s^1);
    }else if(d==2){
        if(!s)v=dfs(x+1,y,3,s^1);
        else v=dfs(x+1,y,1,s^1);
    }else if(d==3){
        if(!s)v=dfs(x,y-1,0,s^1);
        else v=dfs(x,y-1,2,s^1);
    }
    v++;
    return v;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(dp,-1,sizeof(dp));
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++)
            scanf("%s",mp[i]+1);
        int ans=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                int tmp=0;
                for(int k=0;k<4;k++){
                    tmp+=dfs(i,j,k,0);
                }
                ans=max(ans,tmp);
            }
        }
        printf("%d\n",max(ans-3, 0));
    }
    return 0;
}
