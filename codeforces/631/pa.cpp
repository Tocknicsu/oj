#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    //freopen("pa.in", "r", stdin);
    int n;
    scanf("%d", &n);
    ll tmp, ans = 0, now = 0;
    
    for(int i = 0 ; i < 2 ; i++){
        now = 0;
        for(int j = 0 ; j < n ; j++){
            scanf("%I64d", &tmp);
            now |= tmp;
        }
        ans += now;
    }
    printf("%I64d\n", ans);
    return 0;
}
