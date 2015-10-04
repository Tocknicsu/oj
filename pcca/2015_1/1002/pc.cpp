#include <bits/stdc++.h>
using namespace std;
void Solve(){
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    double A[6][6];
    memset(A, 0, sizeof(A));
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            scanf("%lf", &A[i][j]);
    for(int i = 1 ; i <= n - 1; i++){
        for(int k = i+1 ; k <= n ; k++){
            if(A[i][i]){
                double r = A[k][i] / A[i][i];
                for(int j = i+1 ; j <= n ; j++)
                    A[k][j] = A[k][j] - r * A[i][j];
                A[k][i] = r;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++)
            printf("%.1lf%c", A[i][j], j==n?'\n':' ');
    }
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    while(n--){
        Solve();
    }
}
