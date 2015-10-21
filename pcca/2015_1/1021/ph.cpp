#include <bits/stdc++.h>
using namespace std;

int sqr(int x){
    return x * x;
}

void Solve(){
    int n;
    int x, y;
    int score = 0;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &x, &y);
        for(int i = 1 ; i <= 10 ; i++){
            if(sqr(x)+sqr(y) <= sqr(i*20)){
                score += 11 - i;
                break;
            }
        }
    }
    printf("%d\n", score);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
