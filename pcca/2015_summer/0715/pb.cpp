#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first
typedef pair<int, int> PII;
int hd[9][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {0, 0}};
int  d[8][2] = {{-1,-1},{-1,0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
void Solve(){
    int n, m;
    cin >> n >> m;
    string str;
    int t[128][128];
    memset(t, 0, sizeof(t));
    vector<PII> h;
    PII s, e;
    for(int i = 0 ; i < n ; i++){
        cin >> str;
        for(int j = 0 ; j < m ; j++){
            if(str[j]=='Z') h.push_back(PII(i, j));
            else if(str[j]=='A') s = PII(i, j);
            else if(str[j]=='B') e = PII(i, j);
        }
    }
    for(int i = 0 ; i < (int)h.size() ; i++){
        for(int j = 0 ; j < 9 ; j++){
            int nx = h[i].f + hd[j][0];
            int ny = h[i].s + hd[j][1];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            t[nx][ny] = -1;
        }
    }
    queue<PII> Q;
    Q.push(PII(s.f, s.s));
    t[s.f][s.s] = 1;
    t[e.f][e.s] = 0;
    while(Q.size()){
        int x = Q.front().f;
        int y = Q.front().s;
        int dis = t[x][y];
        Q.pop();
        for(int i = 0 ; i < 8 ; i++){
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(t[nx][ny]) continue;
            t[nx][ny] = dis+1;
            Q.push(PII(nx, ny));
        }
    }
    if(t[e.f][e.s] && t[e.f][e.s] != -1){
        cout << "Minimal possible length of a trip is " << t[e.f][e.s] - 1 << endl;
    } else {
        cout << "King Peter, you can't go now!" << endl;
    }
    

}
int main(){
    int n;
    cin >> n;
    while(n--)
        Solve();
    return 0;
}
