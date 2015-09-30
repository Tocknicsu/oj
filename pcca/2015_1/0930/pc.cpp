#include <bits/stdc++.h>
using namespace std;

void Solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> vec(n);
    int now = 0, t;
    long long ans = 0;
    for(int i = 0 ; i < m ; i++){
        scanf("%d", &t);
        now = (now + t) % n;
        ans += vec[now]++;
    }
    printf("%I64d\n", ans+vec[0]);
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
