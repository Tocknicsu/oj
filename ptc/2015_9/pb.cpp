#include <bits/stdc++.h>
using namespace std;
vector<int> ed[512];
vector<int> v;
struct S{
    int x, y, c;
    S(){}
    S(int _x, int _y, int _c) : x(_x), y(_y), c(_c){}
};
vector<S> s;

void Solve(){
    int n, l;
    cin >> n >> l;
    v = vector<int>(n+1);
    vector<int> deg(n+1);
    for(int i = 1 ; i <= n ; i++){
        cin >> v[i];
    }
    s.clear();
    for(int i = 0 ; i <= n ; i++)
        ed[i].clear();
    for(int i = 0 ; i < n - 1 ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        deg[a]++, deg[b]++;
        ed[a].push_back(i);
        ed[b].push_back(i);
        s.push_back(S(a, b, c));
    }
    int start = 0;
    for(int i = 1 ; i <= n ; i++)
        if(deg[i] == 1)
            start = i;
    
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while(n--)
        Solve();
    return 0;
}
