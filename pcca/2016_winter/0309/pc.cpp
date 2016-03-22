#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("pc.in", "r", stdin);
    char str[1024];
    bool ans[1024];
    int len;
    while(scanf("%s", str), len = strlen(str), len >= 2){
        memset(ans, 0, sizeof(ans));
        for(int i = 1 ; i < len ; i++){
            int times = 0;
            for(int j = 1 ; j < i ; j++)
                if(i%j==0 && ans[j])
                    times^=1;
            ans[i] = times ^ (str[i] -'0');
        }
        bool first = true;
        for(int i = 1 ; i < len ; i++){
            if(ans[i]){
                if(first) first = false;
                else printf(" ");
                printf("%d", i);
            }
        }
        printf("\n");
    }
    return 0;
}
