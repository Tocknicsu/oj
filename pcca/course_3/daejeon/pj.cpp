#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> ans;
    for(int x = 1 ; x <= 1000 ; x++)
        for(int y = 1 ; y < x ; y++){
            if(__gcd(x, y) == 1){
                int a = 2 * x * y;
                int b = x * x - y * y;
                if(__gcd(a, b) == 1){
                    ans.push_back(2*(a+b));
                }
            }
        }
    sort(ans.begin(), ans.end());
    for(int i = 1 ; i < (int)ans.size() ; i++){
        ans[i] += ans[i-1];
        if(ans[i] > 1000000){
            ans.resize(i);
            break;
        }
    }
    int n, x;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        printf("%d\n", int(upper_bound(ans.begin(), ans.end(), x) - ans.begin()));
    }
    return 0;
}
