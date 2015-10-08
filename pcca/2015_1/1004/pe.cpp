#include <bits/stdc++.h>
using namespace std;
vector<int> ok;
int main(){
    //freopen("pe.in", "r", stdin);
    int n, m;
    while(scanf("%d", &m), m){
        scanf("%d", &n);
        ok = vector<int>(m+1);
        ok[0] = 1;
        int t;
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &t);
            for(int j = m ; j >= t ; j--)
                ok[j] |= ok[j-t];
        }
        int ans = 0;
        for(int i = 0 ; i <= m ; i++)
            if(ok[i])
                ans = max(ans, i);
        printf("%d\n", ans);
    }
    return 0;
}
