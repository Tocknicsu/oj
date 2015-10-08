#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
int main(){
    bool flag = true;
    int n, tmp;
    int v_max = 0, id_max;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &tmp);
        v.push_back(tmp);
        if(tmp > v_max){
            id_max = i;
            v_max = tmp;
        }
        if(i){
            flag &= v[i] == v[i-1];
        }
    }
    if(flag){
        printf("%lld\n", ll(n) * ll(n-1));
        return 0;
    }
    ll ans = 0;
    for(int i = 1 ; i * i <= n ; i++){
        if(n % i == 0){
        }
    }
    return 0;
}
