#include <bits/stdc++.h>
using namespace std;

void Solve(int a, int b, int c, int d, int &t){
    d += a - c;
    set<int> loop;
    int ans = a - c;
    d %= b;
    while(d){
        d += a;
        d %= b;
        ans += a;
        if(loop.count(d)){
            printf("Case %d: Never\n", t++);
            return;
        }
        loop.insert(d);
    }
    printf("Case %d: %d %d/%d\n", t++, ans / a, ans % a, a);
    return;
}

int main(){
    //freopen("pb.in", "r", stdin);
    int a, b, c, d, t = 1;
    while(scanf("%d%d%d%d", &a, &b, &c, &d), a || b || c || d){
        Solve(a, b, c, d, t);
    }
    return 0;
}
