#include <bits/stdc++.h>
using namespace std;
int X[10240][102];
int m[102];
int main(){
    //freopen("pi.2.in", "r", stdin);
    int w, s;
    int x, y;
    scanf("%d%d%d%d", &w, &s, &x, &y);
    for(int i = 0 ; i < w ; i++)
        for(int j = 0 ; j < x ; j++)
            scanf("%d", &X[i][j]);
    int tmp;
    for(int i = 0 ; i < s ; i++)
        for(int j = 0 ; j < x ; j++){
            scanf("%d", &tmp);
            m[j] = max(m[j], tmp);
        }
    for(int i = 0 ; i < w ; i++){
        for(int j = 0 ; j < x ; j++)
            printf("%d ", min(y-m[j], X[i][j]));
        printf("\n");
    }
}
