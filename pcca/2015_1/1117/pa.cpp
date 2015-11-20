#include <bits/stdc++.h>
using namespace std;
#define INF 1029384756
int v[1024];
void Solve(int n){
    char s[12];
    int l = -INF, r = INF;
    for(int i = 1 ; i <= n ; i++){
        scanf("%s", s);
        if(s[0] == 'x'){
            v[i] = i & 1 ? -INF : INF;
        } else {
            v[i] = atoi(s);
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(i != 1 && abs(v[i]) == INF && abs(v[i-1]) == INF){
            printf("none");
            return;
        }
        if(v[i] == INF || v[i] == -INF){
            if(i&1){
                if(i != 1) r = min(r, v[i-1]);
                if(i != n) r = min(r, v[i+1]);
            } else {
                if(i != 1) l = max(l, v[i-1]);
                if(i != n) l = max(l, v[i+1]);
            }
        } else {
            if(i&1){
                if(i != 1 && v[i-1] <= v[i]){
                    printf("none");
                    return;
                }
                if(i != n && v[i+1] <= v[i]){
                    printf("none");
                    return;
                }
            } else {
                if(i != 1 && v[i-1] >= v[i]){
                    printf("none");
                    return;
                }
                if(i != n && v[i+1] >= v[i]){
                    printf("none");
                    return;
                }
            }
        }
    }
    if(l + 2 <= r){
        if(l + 2 == r){
            printf("%d", l+1);
        } else {
            printf("ambiguous");
        }
    } else {
        printf("none");
    }
}
int main(){
//    freopen("pa.in", "r", stdin);
    int n;
    bool first = true;
    while(scanf("%d", &n), n){
        if(first) first = false;
        else printf("\n");
        Solve(n);
    }
    return 0;
}
