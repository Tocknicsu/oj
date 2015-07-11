#include <bits/stdc++.h>
using namespace std;
int t[128][128];
void Solve(int n, int m){
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++){
            cin >> t[i][j];
            t[i][j] = !t[i][j] ? 1 + t[i-1][j] : 0;
        }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++){
            int tmp = t[i][j];
            for(int k = j + 1 ; k <= m && t[i][k] >= t[i][j] ; k++) tmp += t[i][j];
            for(int k = j - 1 ; k >= 0 && t[i][k] >= t[i][j] ; k--) tmp += t[i][j];
            ans = max(ans, tmp);
        }
    cout << ans << endl;
}

int main(){
    int n, m;
    while(cin >> n >> m, n || m)
        Solve(n, m);
    return 0;
}
