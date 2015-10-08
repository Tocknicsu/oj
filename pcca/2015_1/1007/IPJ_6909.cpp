#include <cstdio>
long long dp[512][512],st[512];
long long ans;
#define MOD 1000000007ll
int main(){
    int T;
    st[0]=1ll;
    for(long long i=1ll;i<=500ll;++i)st[i]=(st[i-1]*i)%MOD;
    scanf("%d",&T);
    for(int t=1;t<=T;++t){
        int n,k,s;
        ans=0ll;
        scanf("%d %d %d",&n,&k,&s);
        for(int i=1;i<=n;++i){
            dp[k][i]=0ll;
            if(i!=s)dp[k][i]=1ll;
        }
        for(int i=k+1;i<n;++i){
            long long now=0ll;
            for(int j=1;j<=n;++j){
                dp[i][j]=0;
                if(j==s)continue;
                if(j==s+1){
                    dp[i][j]=dp[i][j-2]+dp[i-1][j-2];
                }else{
                    dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
                }
                if(j>s)now=(now+dp[i-1][j])%MOD;
            }
            ans=(ans+(now*st[n-i+k-1])%MOD)%MOD;
        }
        long long now=0ll;
        for(int i=1;i<=n;++i){
            if(i==s)continue;
            now=(now+dp[n-1][i])%MOD;
        }
        ans=(ans+(now*st[k-1])%MOD)%MOD;
        printf("Case #%d: %lld\n",t,ans);
    }
    return 0;
}
