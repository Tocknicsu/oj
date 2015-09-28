#include <bits/stdc++.h>
using namespace std;

int main(){
    int s[6] = {};
    int n;
    while(scanf("%d", &n), n)
        s[n]++;
    double ans = 0, total = 0;
    for(int i = 5 ; i > 0 ; i--){
        ans += i * s[i];
        total += s[i];
        printf("%d (%2d) |", i, s[i]);
        for(int j = 0 ; j < s[i] ; j++)
            printf("=");
        printf("\n");
    }
    printf("Average rating: %.4f", ans / total);
    return 0;
}
