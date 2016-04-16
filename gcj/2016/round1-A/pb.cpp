#include <bits/stdc++.h>
using namespace std;

void Solve(int cases){
    int n;
    scanf("%d", &n);
    int h[3000] = {};
    for(int i = 0, j = 2 * n - 1 ; i < j ; i++){
        for(int k = 0 ; k < n ; k++){
            int t;
            scanf("%d", &t);
            h[t]++;
        }
    }
    printf("Case #%d: ", cases);
    for(int i = 0 ; i < 3000 ; i++){
        if(h[i]%2)
            printf("%d ", i);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++)
        Solve(i);
    return 0;
}
