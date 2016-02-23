#include <bits/stdc++.h>
using namespace std;
#define MAX 131072

int v[MAX], ans, deg[MAX];

void Solve(){
    int n;
    ans = 0;
    scanf("%d", &n);
    memset(deg, 0, sizeof(deg));
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &v[i]);
        v[i]--;
        deg[v[i]]++;
    }
    for(int i = 0 ; i < n ; i++)
        if(deg[i] == 0){
            ans++;
            int u = v[i];
            while(1){
                deg[u]--;
                if(deg[u] == 0){
                    deg[u] = -1;
                    ans++;
                    u = v[u];
                } else {
                    break;
                }
            }
        }
    printf("%d\n", ans);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
