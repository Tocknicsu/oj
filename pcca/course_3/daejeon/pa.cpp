#include<bits/stdc++.h>
using namespace std;

void Solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    int x[128] = {}, tmp, ans = 0;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++){
            scanf("%d", &tmp);
            if(tmp){
                ans += (n - x[j] - 1) - i;
                x[j]++;
            }
        }
    printf("%d\n", ans);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
