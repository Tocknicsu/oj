#include <bits/stdc++.h>
using namespace std;
int src[4];
int ans[4];
int gus[4];
int main(){
    while(~scanf("%d", src)){
        for(int i = 1 ; i < 4 ; i++)
            scanf("%d", src+i);
        int n;
        scanf("%d", &n);
        while(n--){
            for(int i = 0 ; i < 4 ; i++)
                ans[i] = src[i];
            int x = 0, y = 0;
            for(int i = 0 ; i < 4 ; i++){
                scanf("%d", gus+i);
                if(ans[i] == gus[i]){
                    ans[i] = gus[i] = 999;
                    x++;
                }
            }
            for(int i = 0 ; i < 4 ; i++)
                for(int j = 0 ; j < 4 ; j++){
                    if(ans[i] == gus[j] && ans[i] != 999){
                        y++;
                        ans[i] = gus[j] = 999;
                    }
                }
            printf("%dA%dB\n", x, y);
        }
    }
}
