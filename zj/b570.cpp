#include <bits/stdc++.h>
using namespace std;
#define MAX 16384
#define f first
#define s second
typedef pair<int, int> PII;
typedef pair< pair<int, int>, bool> ED;
namespace DS{
    int v[MAX], sz;
    void init(int n){
        sz = n;
        for(int i = 0 ; i < n ; i++)
            v[i] = i;
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    void merge(int x, int y){
        x = find(x), y = find(y);
        if(x != y){
            sz--;
            v[x] = y;
        }
    }
    int size(){
        return sz;
    }
};
int main(){
    int n, m;
    vector<ED> ed;
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < m ; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        ed.push_back(ED(PII(x, y), 1));
    }
    int q;
    scanf("%d", &q);
    vector<int> Q(q);
    vector<int> ans(q);
    for(int i = 0 ; i < q ; i++){
        scanf("%d", &Q[i]);
        Q[i]--;
        ed[Q[i]].s = 0;
    }
    DS::init(n);
    for(int i = 0 ; i < m ; i++)
        if(ed[i].s)
            DS::merge(ed[i].f.f, ed[i].f.s);
    for(int i = (int)Q.size() - 1 ; i >= 0 ; i--){
        ans[i] = DS::size();
        DS::merge(ed[Q[i]].f.f, ed[Q[i]].f.s);
    }
    for(int i = 0 ; i < q ; i++){
        printf("%d\n", ans[i]);
    }

    
}
