#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
char m[128][128];
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> m[i];
    int x, y;
    cin >> x >> y;
    m[x][y] = '+';
    queue<PII> Q;
    Q.push(PII(x, y));
    while(Q.size()){
        int nx = Q.front().f;
        int ny = Q.front().s;
        Q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int rx = nx + d[i][0];
            int ry = ny + d[i][1];
            if(rx < 0 || ry < 0 || rx >= n || ry >= n) continue;
            if(m[rx][ry] == '+') continue;
            m[rx][ry] = '+';
            Q.push(PII(rx, ry));
        }
    }
    for(int i = 0 ; i < n ; i++)
        cout << m[i] << endl;
}
