#include <bits/stdc++.h>
using namespace std;

int v[1048576];

void Solve(){
    int n;
    scanf("%d", &n);
    int now = 0;
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &v[i]);
    for(int i = n - 2 ; i >= 0 ; i--)
        now = (now + v[i]) % (n - i + 1);
    printf("%d\n", now+1);
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
