#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int Solve(){
    ll sum = 0, last;
    for(int i = 0 ; i < 5 ; i++){
        scanf("%lld", &last);
        sum += last;
    }
    scanf("%lld", &last);
    for(int i = 0 ; i < 32 ; i++){
        if((sum << i) >= last)
            return i;
    }
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        printf("Case #%d: %d\n", i+1, Solve());
    }
    return 0;
}
