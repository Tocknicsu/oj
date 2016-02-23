#include <bits/stdc++.h>
using namespace std;

int main(){
    int p;
    int a, b;
    scanf("%d", &p);
    while(scanf("%d", &a), a != 0){
        scanf("%d", &b);
        int now = 1, flag = 0;
        a %= p;
        b %= p;
        for(int i = 1 ; i < p ; i++){
            now *= a;
            now %= p;
            if(now == b){
                printf("%d\n", i);
                flag = 1;
                break;
            }
        }
        if(!flag)
            printf("0\n");
    }

}
