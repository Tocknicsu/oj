#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
    int n, tmp;
    scanf("%d", &n);
    vector<ll> sat[2];
    vector<ll> rdis[20];
    int cut = n / 2;
    for(int k = 0 ; k < 2 ; k++)
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &tmp);
            sat[k].push_back(tmp);
        }
    for(int i = (1 << (n - cut)) - 1 ; i >= 0 ; i--){
        int dis=0,p=0;
        for(int j = 0 ; j < (n-cut) ; j++){
            if(i&(1<<j)){
                dis += sat[0][cut+j];
                p++;
            } else {
                dis -= sat[1][cut+j];
            }
        }
        rdis[p].push_back(dis);
    }
    for(int i = 0 ; i <= cut ; i++){
        rdis[i].push_back(-102938475600ll);
        sort(rdis[i].begin(), rdis[i].end());
        rdis[i].resize(unique(rdis[i].begin(), rdis[i].end())-rdis[i].begin());
    }
    
    ll ans = 2147483647;
    for(int i = (1 << cut) - 1 ; i >= 0 ; i--){
        int dis=0, p=0;
        for(int j = 0 ; j < (n-cut) ; j++){
            if(i&(1<<j)){
                dis += sat[0][j];
                p++;
            } else {
                dis -= sat[1][j];
            }
        }
        ans = min(ans, (abs(dis+(*lower_bound(rdis[cut-p].begin(), rdis[cut-p].end(), -dis)))));
        if(dis > 0){
            ans = min(ans, abs(dis+(*(lower_bound(rdis[cut-p].begin(), rdis[cut-p].end(), -dis)-1))));
        } else {
            ans = min(ans, abs(dis+(*(upper_bound(rdis[cut-p].begin(), rdis[cut-p].end(), -dis)))));
        }
        if(n&1){
            ans = min(ans, (abs(dis+(*lower_bound(rdis[cut-p+1].begin(), rdis[cut-p+1].end(), -dis)))));
            if(dis > 0){
                ans = min(ans, abs(dis+(*(lower_bound(rdis[cut-p+1].begin(), rdis[cut-p+1].end(), -dis)-1))));
            } else {
                ans = min(ans, abs(dis+(*(upper_bound(rdis[cut-p+1].begin(), rdis[cut-p+1].end(), -dis)))));
            }
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
