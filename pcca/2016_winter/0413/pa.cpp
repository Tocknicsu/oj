#include <bits/stdc++.h>
using namespace std;
int deg[100] = {0};
vector<int> vc[100];
int main(){
    int M, N;
    scanf("%d%d", &M, &N);
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        vc[a].push_back(b);
        vc[b].push_back(a);
        deg[a]++, deg[b]++;
    }
    int ans = 0;
    while(true){
        for(int i=0;i<N;i++){
            if(deg[i] == 1){
                int v;
                for(int u: vc[i]){
                    if(deg[u] > 0)
                        v = u;
                }
                for(int u: vc[v]){
                    deg[u]--;
                }
                deg[v] = -1;
                ans++;
            }
        }
        int v = -1, md = 0;
        for(int i=0;i<N;i++){
            if(deg[i] > 0 && deg[i] > md){
                md = deg[i], v = i;
            }
        }
        if(v == -1)break;
        for(int u: vc[v])
            deg[u]--;
        deg[v] = -1;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}

