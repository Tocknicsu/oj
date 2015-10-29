#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
#define MAX 16384
vector<PII> ed[MAX];
PII dis[MAX];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    fill(dis, dis+MAX, PII(1029384756, 0));
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int a, b, c;;
        cin >> a >> b >> c;
        ed[a].push_back(PII(b, c));
    }
    int start, end;
    cin >> start >> end;
    dis[start] = PII(0, 1);
    priority_queue<PII, vector<PII>, greater<PII> > PQ;
    PQ.push(PII(dis[start].f, start));
    while(PQ.size()){
        PII tmp = PQ.top(); PQ.pop();
        if(tmp.f > dis[end].f) continue;
        if(tmp.f > dis[tmp.s].f) continue;
        for(int i = 0 ; i < (int)ed[tmp.s].size() ; i++){
            int nx = ed[tmp.s][i].f;
            int nd = dis[tmp.s].f + ed[tmp.s][i].s;
            if(nd < dis[nx].f){
                dis[nx].f = nd;
                dis[nx].s = 0;
                PQ.push(PII(nd, nx));
            }
            if(nd == dis[nx].f)
                dis[nx].s += dis[tmp.s].s;
        }
    }
    cout << dis[end].s << endl;
    return 0;
}
