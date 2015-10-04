#include <bits/stdc++.h>
using namespace std;

void Solve(){
    int n;
    scanf("%d", &n);
    double v[8][8];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            scanf("%lf", &v[i][j]);
    bool flag = true;
    for(int i = 0 ; i < n ; i++){
        double tmp = 0;
        for(int j = 0 ; j < n ; j++)
            if(i==j) continue;
            else tmp += fabs(v[i][j]);
        flag &= abs(v[i][i]) > tmp;
    }
    printf("%c", flag ? 'Y' : 'N');
}

int main(){
//   freopen("tpb.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    printf("\n");
}
