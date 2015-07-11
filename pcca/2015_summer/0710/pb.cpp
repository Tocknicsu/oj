#include <iostream>
using namespace std;
int t[128][128];
int tmp[128];
void Solve(int n){
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            cin >> t[i][j];
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            t[i][j] += t[i-1][j];
    int ans = t[1][1];
    for(int i = 0 ; i < n ; i++)
        for(int j = i + 1 ; j <= n ; j++){
            for(int k = 1 ; k <= n ; k++){
                tmp[k] = t[j][k] - t[i][k];
                tmp[k] += tmp[k-1] > 0 ? tmp[k-1] : 0;
                ans = max(ans, tmp[k]);
            }
        }
    cout << ans << endl;
}

int main(){
    int n;
    while(cin >> n)
        Solve(n);
    return 0;
}
