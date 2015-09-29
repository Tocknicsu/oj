#include <bits/stdc++.h>
using namespace std;
#define sqr(x) ((x)*(x))
#define f first
#define s second
int N;
double mp[100][100];
double x[100],y[100],z[100];
char n[100],nn[100];
map<string, int> m;
int sn;
void init(){
    sn = 0;
    m.clear();
}
int find(const char *s){
    if(m.find(s)==m.end())
        m[s] = sn++;
    return m[s];
}
int main(){
    int c=1;
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d",&N);
        for(int i=0;i<N;i++)
            scanf("%s%lf%lf%lf",n,&x[i],&y[i],&z[i]),find(n);
        for(int i=0;i<N;i++){
            mp[i][i] = 0.0;
            for(int j=i+1;j<N;j++){
                mp[i][j] = mp[j][i] = sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])+sqr(z[i]-z[j]));
            }
        }
        int w;
        scanf("%d",&w);
        for(int i=0;i<w;i++){
            scanf("%s%s",n,nn);
            int id1=find(n),id2=find(nn);
            mp[id1][id2] = 0;
        }
        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    double tmp=mp[i][k]+mp[k][j];
                    if(mp[i][j]>tmp)
                        mp[i][j]=tmp;
                }
            }
        }
        printf("Case %d:\n", c++);
        int Q;
        scanf("%d",&Q);
        for(int i=0;i<Q;i++){
            scanf("%s%s",n,nn);
            printf("The distance from %s to %s is %d parsecs.\n", n, nn, (int)round(mp[find(n)][find(nn)]));
        }
    }
    return 0;
}
