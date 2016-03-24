#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("pa.in", "r", stdin);
    int a, b, c, d;
    while(scanf("%d%d%d%d", &a, &b, &c, &d), a || b || c || d){
        printf("%d %d\n", c - b, d - a);
    }
}
