#include <bits/stdc++.h>
using namespace std;
struct C{
    int x, y, r;
    C(){}
    C(int _x, int _y, int _r):x(_x),y(_y),r(_r){}
};
inline int squ(int x){
    return x * x;
}
void Solve(int n){
    vector<C> c;
    bool go[n][n];
    memset(go, 0, sizeof(go));
    for(int i = 0 ; i < n ; i++){
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        for(int j = 0 ; j < i ; j++){
            int dis = squ(c[j].x-x) + squ(c[j].y-y);
            go[i][j] = dis <= squ(r);
            go[j][i] = dis <= squ(c[j].r);
        }
        c.push_back(C(x, y, r));
    }
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                go[i][j] |= go[i][k] & go[k][j];
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        bool flag = true;
        for(int j = 0 ; j < n ; j++)
            if(i==j) continue;
            else flag &= go[j][i];
        ans += flag;
    }
    printf("%d\n", ans);
}
int main(){
    int n;
    while(scanf("%d", &n), n){
        Solve(n);
    }
}
