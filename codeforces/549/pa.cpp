#include <bits/stdc++.h>
using namespace std;
char table[52][52];
bool judge(int x, int y){
    int c[256] = {};
    for(int i = x ; i <= x+1 ; i++)
        for(int j = y ; j <= y+1 ; j++)
            c[(int)table[i][j]]++;
    return c[(int)'f'] && c[(int)'a'] && c[(int)'c'] && c[(int)'e'];
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        cin >> table[i];
    int ans = 0;
    for(int i = 0 ; i < n - 1 ; i++)
        for(int j = 0 ; j < m - 1 ; j++)
            ans += judge(i, j);
    cout << ans << endl;
}
