#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int a, b;
    map<int, int> t;
    for(int i = 0 ; i < m ; i++){
        scanf("%d%d", &a, &b);
        if(a > b) continue;
        t[a] += 1;
        t[b] -= 1;
    }
    t[n+1] = 0;
    int last = 0, last_status = 0;
    int ans = 0;
    for(auto x : t){
        int now = x.first;
        int now_status = x.second;
        int di = now - last;
        if(last_status){
            ans += di * 3;
        } else {
            ans += di;
        }
        last = now;
        last_status += now_status;
    }
    printf("%d\n", ans);
    return 0;
}
