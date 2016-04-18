#include <bits/stdc++.h>
using namespace std;

int sqr(int x){
    return x * x;
}
void die(){
    printf("NO\n");
    exit(0);
}

int main(){
    int a[2][3];
    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < 3 ; j++)
            scanf("%d", &a[i][j]);
    sort(a[0], a[0]+3);
    sort(a[1], a[1]+3);
    if(sqr(a[0][0]) + sqr(a[0][1]) != sqr(a[0][2])){
        die();
    }
    for(int i = 0 ; i < 3 ; i++)
        if(a[0][i] != a[1][i])
            die();
    printf("YES\n");
    return 0;
}
