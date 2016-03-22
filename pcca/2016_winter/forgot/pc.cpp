#include <bits/stdc++.h>
using namespace std;
int table[3000][512];
int b, c;
int alargeb(int x, int y){
    int now = 0;
    for(int i = 0 ; i < b ; i++)
        if(table[x][i] < table[y][i])
            now++;
        else 
            now--;
    return now;
}
int main(){
//    freopen("pc.in", "r", stdin);
    int t = 1;
    while(scanf("%d%d", &b, &c), b || c){
        int x;
        for(int i = 0 ; i < b ; i++){
            for(int j = 0 ; j < c ; j++){
                scanf("%d", &x);
                table[x][i] = j;
            }
        }
        queue<int> Q;
        for(int i = 0 ; i < c ; i++)
            Q.push(i);
        while(Q.size() != 1){
            int x = Q.front(); Q.pop();
            int y = Q.front(); Q.pop();
            int g = alargeb(x, y);
            if(g == 0 && Q.size()){
            } else if(g > 0) {
                Q.push(x);
            } else {
                Q.push(y);
            }
        }
        bool ans = 1;
        for(int i = 0 ; i < c ; i++){
            if(i == Q.front()) continue;
            if(alargeb(i, Q.front()) >= 0) ans = 0;
        }
        if(ans){
            printf("Case %d: %d\n", t++, Q.front());
        } else {
            printf("Case %d: No Condorcet winner\n", t++);
        }
        
    }
    return 0;
}
