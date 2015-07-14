#include <bits/stdc++.h>
using namespace std;
#define INF 1029384756
typedef pair<int, int> PII;
typedef pair<PII, int> PPI;
char t[1024][1024];
bool v[1024][1024];
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    PII start;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> t[i];
        for(int j = 0 ; j < m ; j++){
            if(t[i][j] == 'E'){
                start.first = i;
                start.second = j;
                v[i][j] = 1;
            }
        }
    }
    int end = INF;
    int ans = 0;
    queue<PPI> Q;
    Q.push(PPI(start, 0));
    while(Q.size()){
        PPI tmp = Q.front(); Q.pop();
        if(tmp.second > end){
            break;
        }
        int x = tmp.first.first;
        int y = tmp.first.second;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(t[nx][ny] == 'T' || v[nx][ny]) continue;
            v[nx][ny] = true;
            if(isdigit(t[nx][ny])){
                ans += t[nx][ny] - '0';
                Q.push(PPI(PII(nx, ny), tmp.second+1));
            } else if(t[nx][ny] == 'S'){
                end = tmp.second;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
