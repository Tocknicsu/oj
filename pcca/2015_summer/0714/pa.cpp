#include <bits/stdc++.h>
using namespace std;

namespace DS{
    const int MAX = 32768;
    int v[MAX];
    int sz[MAX];
    int max_sz;
    void init(int n){
        for(int i = 0 ; i < n ; i++)
            v[i] = i, sz[i] = 1;
        max_sz = 1;
    }
    int find(int x){
        return v[x] == x ? v[x] : v[x] = find(v[x]);
    }
    void merge(int x, int y){
        x = find(x), y = find(y);
        if(x==y) return;
        v[x] = y;
        sz[y] += sz[x];
        sz[x] = 0;
        max_sz = max(sz[y], max_sz);
    }
};
void Solve(){
    int n, m;
    cin >> n >> m;
    DS::init(n);
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        DS::merge(a, b);
    }
    cout << DS::max_sz << endl;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while(n--)
        Solve();
}
