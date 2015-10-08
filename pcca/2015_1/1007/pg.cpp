#include <bits/stdc++.h>
using namespace std;
bool ok[1024];
int cnt[2];
vector<int> p;
int dfs(int now,int n,int x,int k){
    if(now==x){
        int ret=k;       
        for(int i=x;i<(int)p.size();++i){
            cnt[0]=cnt[1]=0;
            for(int j=p[i];j<=n;j+=p[i]){
                cnt[ok[j]]++;
            }
            if(cnt[0]>cnt[1])ret+=(cnt[0]-cnt[1]);
        }   
        return ret;
    }
    int ret=0;
    ret=max(dfs(now+1,n,x,k),ret);
    int &y=p[now];
    for(int i = y;i <= n;i += y){
        if(ok[i])k--,ok[i]=0;
        else k++,ok[i]=1;
    }
    ret=max(dfs(now+1,n,x,k),ret);
    for(int i = y;i <= n;i+=y){
        if(ok[i])k--,ok[i]=0;
        else k++,ok[i]=1;
    }
    return ret;
}
unordered_map<int,bool> ma;
int Solve(){
    int n, m;
    ma.clear();
    p.clear();
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < m ; i++){
        int x;
        scanf("%d", &x);
        if(!ma[x]){
            ma[x]=1;
            p.push_back(x);
        }
    }
    sort(p.begin(), p.end());
    int x = 0;
    for( ; x+1  < (int)p.size() && p[x]*p[x+1] <= n ; x++);
    return dfs(0,n,x,0);
}

int main(){
//    freopen("pg.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++)
        printf("Case #%d: %d\n", i, Solve());
    return 0;
}
