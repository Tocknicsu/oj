#include <bits/stdc++.h>
using namespace std;
int m[16][16];
void Solve(){
    int x, y;
    cin >> x >> y;
    for(int i = 0 ; i < x ; i++)
        for(int j = 0 ; j < y ; j++)
            cin >> m[i][j];
    for(int i = 0 ; i < x ; i++)
        for(int j = 0 ; j < y ; j++){
            if(m[i][j] != m[x-i-1][y-j-1]){
                cout << "keep defending" << endl;
                return;
            }
        }
    cout << "go forward" << endl;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while(n--)
        Solve();
    return 0;
}
