#include <bits/stdc++.h>
using namespace std;
bool use[1048576];
int main(){
    int n;
    cin >> n;
    char c[2];
    int x;
    int now = 0;
    int ans = 0;
    while(n--){
        cin >> c >> x;
        if(c[0] == '-'){
            if(use[x]){
                now--;
                use[x] = false;
            } else {
                ans++;
            }
        } else {
            if(!use[x]){
                use[x] = true;
                now++;
            }
        }
        ans = max(ans, now);
    }
    cout << ans << endl;

}
