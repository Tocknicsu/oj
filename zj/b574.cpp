#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int ans = 0, now = 0;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        now += y ? 1 : -1;
        ans = max(ans, now);
    }
    printf("%d\n", ans);
    
    return 0;
}
