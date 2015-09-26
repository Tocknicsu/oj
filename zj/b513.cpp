#include <bits/stdc++.h>
using namespace std;
#define MAX 65536
bool v[MAX];
void bulid(){
    for(int i = 4 ; i < MAX ; i+=2)
        v[i] = 1;
    for(int i = 3 ; i * i < MAX ; i+=2)
        if(!v[i])
            for(int j = i * i ; j < MAX ; j += 2 * i)
                v[j] = 1;
}

int main(){
    bulid();
    int n;
    scanf("%d", &n);
    while(n--){
        int t;
        scanf("%d", &t);
        printf("%s\n", v[t]?"N":"Y");
    }
    return 0;
}
