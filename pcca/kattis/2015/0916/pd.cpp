/*
給定二維最標點
求曼哈頓距離的MST
*/
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define MAX 1024
typedef pair<int, int> PII;
PII m[MAX][MAX];
namespace DS{
    int v[MAX*MAX];
    void init(){
        for(int i = 0 ; i < MAX * MAX ; i++)
            v[i] = i;
    }
    int find(int x){
        return x == v[x] ? x : v[x] = find(v[x]);
    }
    void merge(int x, int y){
        v[find(x)] = find(y);
    }
};
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main(){
    DS::init();
    memset(m, -1, sizeof(m));
    int n;
    scanf("%d", &n);
    queue<PII> Q;
    for(int i = 0 ; i < n ; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        m[x][y] = PII(0, i);
        Q.push(PII(x,y));
    }
    int ans = 0;
    while(Q.size()){
        int x = Q.front().f;
        int y = Q.front().s;
        Q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if(nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue;
            if(m[nx][ny].f != -1){
                if(DS::find(m[nx][ny].s) != DS::find(m[x][y].s)){
                    DS::merge(m[nx][ny].s, m[x][y].s);
                    ans += m[nx][ny].f + m[x][y].f + 1;
                }
            } else {
                m[nx][ny] = PII(m[x][y].f+1, m[x][y].s);
                Q.push(PII(nx, ny));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
