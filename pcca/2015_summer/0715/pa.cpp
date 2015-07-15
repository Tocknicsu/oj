#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define f first
#define s second
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
bool t[1024][1024];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    while(cin >> n >> m, n || m){
        memset(t, 0, sizeof(t));
        int r;
        cin >> r;
        for(int i = 0 ; i < r ; i++){
            int x, nums, y;
            cin >> x >> nums;
            for(int i = 0 ; i < nums ; i++){
                cin >> y;
                t[x][y] = true;
            }
        }
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        t[sx][sy] = true;
        queue<PIP> Q;
        Q.push(PIP(0, PII(sx, sy)));
        while(Q.size()){
            int dis = Q.front().f;
            int x = Q.front().s.f;
            int y = Q.front().s.s;
            Q.pop();
            if(x == ex && y == ey){
                cout << dis << endl;
                break;
            }
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(t[nx][ny]) continue;
                t[nx][ny] = true;
                Q.push(PIP(dis+1, PII(nx, ny)));
            }
        }
    }
    return 0;
}
