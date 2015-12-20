#include <bits/stdc++.h>
using namespace std;
struct S{
    int v, w;
};

int main(){
    int n, l, wa, wb;
    while(1){
        scanf("%d%d%d%d\n", &n, &l, &wa, &wb);
        S s[n];
        for(int i = 0 ; i < n ; i++){
            scanf("%d %d", &s[i].v, &s[i].w);
        }
        int ans = -1;
        for(int i = (1 << n) - 1 ; i > 0 ; i--){
            int items = 0, w = 0, v = 0;
            for(int j = 0 ; j < n ; j++){
                if(i & 1 << j){
                    items++;
                    w += s[j].w;
                    v += s[j].v;
                }
            }
            if(items >= l && w >= wa && w <= wb){
                ans = max(ans, v / w + (v % w != 0));
            }
        }
        printf("%d\n", ans);
        int next;
        scanf("%d", &next);
        if(next) break;
    }
    return 0;
}
