#include <bits/stdc++.h>
using namespace std;
#define MAX 128
typedef long long ll;
ll A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
void Solve(){
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            scanf("%lld", &A[i][j]);
    for(int i = 0 ; i < m ; i++)
        for(int j = 0 ; j < p ; j++)
            scanf("%lld", &B[i][j]);
    memset(C, 0, sizeof(C));
    for(int k = 0 ; k < m ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < p ; j++)
                C[i][j] += A[i][k] * B[k][j];
    ll ans = C[0][0];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < p ; j++)
            ans = max(ans, C[i][j]);
    printf("%lld\n", ans);

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
