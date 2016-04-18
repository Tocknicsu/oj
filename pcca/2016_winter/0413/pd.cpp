#include <bits/stdc++.h>
using namespace std;
#define MAX 256

struct LINE{
    int x1, x2;
    int y1, y2;
    int type;
};
vector<int> ed[256];

bool dfs(int now, int p, int d, int first){
    if(d == 4)
        return now == first;
    for(int i = 0 ; i < (int)ed[now].size() ; i++){
        int &u = ed[now][i];
        if(u == p) continue;
        if(dfs(u, now, d+1, first))
            return true;
    }
    return false;
}
bool inter(LINE a, LINE b){
    if(a.type == -1) swap(a, b);
    return b.x1 <= a.x1 && a.x1 <= b.x2 && a.y1 <= b.y1 && b.y1 <= a.y2;
}

void Solve(){
    for(int i = 0 ; i < 256 ; i++)
        ed[i].clear();
    int n;
    scanf("%d", &n);
    vector<LINE> line(n);
    for(int i = 0 ; i < n ; i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        line[i].x1 = min(x1, x2);
        line[i].x2 = max(x1, x2);
        line[i].y1 = min(y1, y2);
        line[i].y2 = max(y1, y2);
        if(line[i].x1 == line[i].x2) line[i].type = 1;
        else line[i].type = -1;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(line[i].type * line[j].type == 1) continue;
            if(inter(line[i], line[j])){
                ed[i].push_back(j);
                ed[j].push_back(i);
            }
        }
        if(dfs(i, -1, 0, i)){
            printf("%d\n", i+1);
            return;
        }
    }
    printf("none\n");
}

int main(){
//    freopen("pd.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
