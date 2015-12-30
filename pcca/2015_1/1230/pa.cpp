#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
#define f first
#define s second
int main(){
    //freopen("pa.in", "r", stdin);
    int n, m;
    while(scanf("%d%d", &n, &m), n || m){
        deque<PLL> Q;
        ll ans = LLONG_MIN;
        ll tmp;
        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &tmp);
            if(Q.size() && i - Q.front().f > m) Q.pop_front();
            if(Q.empty()){
                Q.push_back(PLL(i, tmp));
            } else {
                ans = max(ans, tmp - Q.front().s);
                while(Q.size() && Q.back().s >= tmp)
                    Q.pop_back();
                Q.push_back(PLL(i, tmp));
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
