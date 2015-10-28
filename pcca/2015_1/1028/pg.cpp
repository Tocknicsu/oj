#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<double, int> PDI;

void Solve(){
    int n;
    scanf("%d", &n);
    priority_queue<int> PQ[128];
    char s[2];
    int t, st, r;
    for(int i = 0 ; i < n ; i++){
        scanf("%s", s);
        if(s[0] == 'P'){
            scanf("%d %d %d", &t, &st, &r);
            PQ[r].push(st - r * t);
        } else {
            scanf("%d", &t);
            int ser = -1029384756, id = 0;
            for(int j = 100 ; j >= 0 ; j--){
                if(PQ[j].empty()) continue;
                int now = PQ[j].top() + j * t;
                if(now > ser){
                    ser = now, id = j;
                }
            }
            printf("%d %d\n", ser, id);
            PQ[id].pop();
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        printf("Case #%d:\n", i+1);
        Solve();
    }
    return 0;
}
