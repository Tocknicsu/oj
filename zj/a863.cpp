#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(~scanf("%d", &n)){
        printf("%d is ", n);
        int next = 0, times=0;
        while(n!=1 && times <= 100){
            next = 0;
            while(n){
                next += (n % 10) * (n % 10);
                n /= 10;
            }
            ++times;
            n = next;
        }
        printf("%s\n", n==1?"a happy number":"an unhappy number");
    }
    return 0;
}
