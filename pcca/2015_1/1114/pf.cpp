#include <bits/stdc++.h>
using namespace std;
#define MAX 2048576
int n, w, m;
int road[MAX];
int done[MAX];

bool check(int x){
    memset(done, 0, sizeof(done));
    int now = 0;
    int de = 0;
    for(int i = 0 ; i < n ; i++){
        now += done[i];
        if(now < road[i]){
            int down = road[i] - now;
            int time = down / x + (down % x != 0);
            de += time;
            now += x * time;
            done[i+w] -= x * time;
        }
        if(de > m) return false;
    }
    return true;
}

void Solve(){
    int now = 0, step = 0, max_x;
    scanf("%d%d%d", &n, &w, &m);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &road[i]);
        step = max(step, road[i]);
    }
    max_x = step;
    while(step && now < max_x){
        if(check(now + step)){
            step >>= 1;
        } else {
            now += step;
        }
    }
    printf("%d\n", now >= max_x ? -1 : now + 1);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
