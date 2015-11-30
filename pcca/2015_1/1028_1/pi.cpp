#include <bits/stdc++.h>
using namespace std;

int cnt[128];
int main(){
    //freopen("pi.in", "r", stdin);
    int n, m, t;
    scanf("%d%d", &n, &m);
    int avg = n / m, ans = 0;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &t);
        if(cnt[t] < avg) cnt[t]++;
        else ans++;
    }
    printf("%d\n", ans);
    return 0;
}
