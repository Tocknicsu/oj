#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[4096][2];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%lld%lld", &c[i][0], &c[i][1]);
        if(c[i][0] < c[i][1]) swap(c[i][0], c[i][1]);
    }
    ll ans = 0, k[2] = {};
    for(int i = 0 ; i < n ; i++){
        ll now = 0;
        for(int j = 0 ; j < n ; j++){
            if(c[j][0] >= c[i][0] && c[j][1] >= c[i][1])
                now += c[i][0] * c[i][1];
            else if(c[j][1] >= c[i][0] && c[j][0] >= c[i][1])
                now += c[i][0] * c[i][1];
        }
        if(now > ans){
            k[0] = c[i][0];
            k[1] = c[i][1];
            ans = now;
        }
    }
    printf("%lld\n%lld %lld\n", ans, k[0], k[1]);
    
    return 0;
}
