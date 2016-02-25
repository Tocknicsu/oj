#include <bits/stdc++.h>
using namespace std;

void Solve(int n){
    int s[2][400];
    memset(s, 0, sizeof(s));
    char str[2];
    int a, b;
    for(int i = 0 ; i < n ; i++){
        scanf("%s%d%d", str, &a, &b);
        for(int j = min(a, b) ; j <= max(a, b) ; j++)
            s[str[0] == 'M'][j]++;
    }
    int ans = 0;
    for(int i = 0 ; i < 400 ; i++)
        ans = max(ans, min(s[0][i], s[1][i]));
    printf("%d\n", ans * 2);
}

int main(){
//    freopen("pb.in", "r", stdin);
    int n;
    while(~scanf("%d", &n)){
        Solve(n);
    }
    return 0;
}
