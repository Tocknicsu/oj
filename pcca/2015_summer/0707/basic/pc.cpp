#include <iostream>
using namespace std;
int m[20][20] = {};
int D[4][2] = {{-1,1},{0, 1},{1, 1},{1, 0}};
bool ok(int x, int y, int k, int d, int l){
    if(x < 0 || y < 0 || x > 19 || y > 19) return false;
    if(m[x][y] != k) return false;
    if(l == 0){
        int nx = x - D[d][0];
        int ny = y - D[d][1];
        if(nx < 0 || ny < 0 || nx > 19 || ny > 19){
        } else {
            if(m[nx][ny] == k)
                return false;
        }
    }
    if(l == 5) return m[x][y] == k;
    if(l == 4)
        return !ok(x+D[d][0], y+D[d][1], k, d, l+1);
    return ok(x+D[d][0], y+D[d][1], k, d, l+1);
}

void Solve(){
    for(int i = 0 ; i < 19 ; i++)
        for(int j = 0 ; j < 19 ; j++)
            cin >> m[i][j];
    for(int k = 1 ; k < 3 ; k++)
        for(int i = 0 ; i < 19 ; i++)
            for(int j = 0 ; j < 19 ; j++){
                for(int d = 0 ; d < 4 ; d++)
                if(ok(i, j, k, d, 0)){
                    cout << k << endl;
                    cout << i + 1 << ' ' << j + 1 << endl;
                    return;
                }
            }
    cout << 0 << endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while(n--)
        Solve();
    return 0;
}
