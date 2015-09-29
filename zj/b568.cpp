#include <bits/stdc++.h>
using namespace std;
#define MAX 700012
bool ok[MAX*2];
int main(){
    ok[0] = 1;
    int n;
    scanf("%d", &n);
    while(n--){
        int t;
        scanf("%d", &t);
        for(int i = MAX * 2 - 1 ; i >= t ; i--)
            ok[i] |= ok[i-t];
        for(int i = MAX * 2 - 1 ; i > 700000 ; i--)
            ok[i%700000] |= ok[i];
    }
    for(int i = 700000 ; i >= 0 ; i--)
        if(ok[i]){
            printf("%d\n", i);
            return 0;
        }

}
