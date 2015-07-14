#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int d[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},{0, -1}, {0, 1},{1, -1}, {1, 0}, {1, 1}};

int main(){
    int n, m;
    string str[128];
    while(cin >> n >> m, n || m){
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            cin >> str[i];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(str[i][j] == '@'){
                    ans++;
                    queue<PII> Q;
                    str[i][j] = ' ';
                    Q.push(PII(i, j));
                    while(Q.size()){
                        int x = Q.front().first;
                        int y = Q.front().second;
                        Q.pop();
                        for(int k = 0 ; k < 8 ; k++){
                            int nx = x + d[k][0];
                            int ny = y + d[k][1];
                            if(x < 0 || y < 0 || x >= n || y >= m) continue;
                            if(str[nx][ny] != '@') continue;
                            Q.push(PII(nx, ny));
                            str[nx][ny] = ' ';
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
