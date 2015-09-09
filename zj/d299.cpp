#include <bits/stdc++.h>
using namespace std;

/*
FORTYENSIX
0123456789
*/
int a[10];
int forty(){
    return a[0] * 10000 + a[1] * 1000 + a[2] * 100 + a[3] * 10 + a[4];
}
int ten(){
    return a[3] * 100 + a[5] * 10 + a[6];
}
int sixty(){
    return a[7] * 10000 + a[8] * 1000 + a[9] * 100 + a[3] * 10 + a[4];
}
bool check(){
    return forty() + ten() + ten() == sixty();
}
void print(){
    printf("%d + %d + %d = %d\n", forty(), ten(), ten(), sixty());
}
int main(){
    for(int i = 0 ; i < 10 ; i++)
        a[i] = i;
    do{
        if(check()){
            print();
        }
    } while(next_permutation(a, a+10));
}
