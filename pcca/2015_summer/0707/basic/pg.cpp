#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ED{
    int to, id;
    ED(){}
    ED(int _to, int _id) : to(_to), id(_id) {}
    bool operator<(const ED &b) const {
        return to < b.to;
    }
};
vector<ED> ed[5];
int cnt = 0;
void add_edge(int a, int b){
    ed[a].push_back(ED(b, cnt));
    ed[b].push_back(ED(a, cnt++));
}
vector<int> ans;
bool v[8];
void DFS(int now){
    if(ans.size() == 9){
        for(int i = 0 ; i < 9 ; i++)
            cout << ans[i]+1;
        cout << endl;
        return;
    }
    for(int i = 0 ; i < (int)ed[now].size() ; i++){
        ED x = ed[now][i];
        if(v[x.id]) continue;
        ans.push_back(x.to);
        v[x.id] = true;
        DFS(x.to);
        ans.pop_back();
        v[x.id] = false;
    }
}
int main(){
    add_edge(0, 4); add_edge(0, 2); add_edge(0, 1);
    add_edge(1, 4); add_edge(1, 2);
    add_edge(2, 4); add_edge(2, 3);
    add_edge(3, 4);
    for(int i = 0 ; i < 5 ; i++)
        sort(ed[i].begin(), ed[i].end());
        ans.push_back(0);
        DFS(0);
        ans.pop_back();
    return 0;
}
