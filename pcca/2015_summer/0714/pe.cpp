#include <iostream>
using namespace std;
bool exist[16384];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, x, ans = 0;
    cin >> n >> m;
    int sz = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> x;
        if(!exist[x]){
            exist[x] = 1;
            sz++;
            if(sz == m){
                ans++;
                fill(exist, exist+m+1, 0);
                sz = 0;
            }
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
