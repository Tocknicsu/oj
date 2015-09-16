#include <bits/stdc++.h>
using namespace std;
#define MAX 1048576
int num[1048576];
void build(){
    for(int i = 0 ; i < MAX ; i++){
        int tmp = i, add = i;
        while(tmp){
            add += tmp % 10;
            tmp /= 10;
        }
        num[add]++;
    }
}
int main(){
    build();
    for(int i = 1 ; i <= 1000000 ; i++)
        if(!num[i])
            cout << i << endl;
    
}
