#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
#define LL long long
#define N 507
#define MOD 1000000007
LL a[N];
LL c[N][N];
void init(){
    LL i,j;
    // A
    a[0]=1;
    for(i=1;i<N;++i) a[i]=(a[i-1]*i)%MOD;
    // C
    for(i=0;i<N;++i)
    for(j=0;j<=i;++j)
    if(j==0 || j==i){
        c[i][j]=1;
    }
    else{
        c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
    }
}
int main(){
    freopen("pd.in", "r", stdin);
    int T,tt=0;
    int n,m,p;
    int i,j;
    LL ans;
    init();
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&p);
        ans=0;
        // end
        if(n-p<m){
//            ans=a[n-p]*c[p-1][m-1-(n-p)]%MOD*a[m-1-(n-p)]%MOD;
            ans=c[m-1][n-p]*a[n-p]%MOD*c[p-1][m-1-(n-p)]%MOD*a[m-1-(n-p)]%MOD;
        }
        // between
        for(j=1;j<=n-m;++j){
            for(i=1;i<=min(n-p,j);++i){
                ans=(ans+c[n-p][i]*c[p-1][j-i]%MOD*a[n-1-j]%MOD)%MOD;
            }
        }
        printf("Case #%d: %lld\n",++tt,ans);
    }
    return 0;
}




