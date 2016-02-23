#include <bits/stdc++.h>
using namespace std;
char str[128];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d%s", &n, str);
        int now = 0, ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(str[i] == '(') now++;
            else{
                now--;
                if(now < 0)
                    now += 2, ans++;
            }
        }
        printf("%d\n", ans + now / 2);
    }
}
