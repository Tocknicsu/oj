#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("pg.in", "r", stdin);
    int a, b, c;
    while(~scanf("%d%d%d", &a, &b, &c)){
        int x = a * b, y = c - b;
        int z = __gcd(x, y);
        printf("%d/%d\n", x / z,y / z);
    }
}
