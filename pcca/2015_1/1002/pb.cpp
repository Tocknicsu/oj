#include <bits/stdc++.h>
using namespace std;

void Solve(){
    int n, t = 0;
    scanf("%d", &n);
    while(n){
        t += n & 1;
        n >>= 1;
    }
    printf("%d\n", t&1);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
