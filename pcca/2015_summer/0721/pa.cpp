#include <bits/stdc++.h>
using namespace std;
const int MAX = 262144;
int v[MAX] * 2;
void build();
int main(){
    int n;
    char s[6];
    while(scanf("%d", &n), n){
        for(int i = 0 ; i < n ; i++)
            scanf("%d", v+MAX+i);
        build();
        while(scanf("%s", s)){
            if(s[0] == 'E') break;

        }
        
    }
    return 0;
}
