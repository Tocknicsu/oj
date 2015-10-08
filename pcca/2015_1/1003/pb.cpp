#include <bits/stdc++.h>
using namespace std;
int f(int x){
    int re = 0;
    while(x){
        re += x & 1;
        x >>= 1;
    }
    return re;
}

int main(){
    int k = 0;
    for(int i = 1 ; i <= 200 ; i++){
        k += (1 << f(i));
        printf("%d %d\n", i, k);
    }
}
