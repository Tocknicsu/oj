#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define MAX 262144
typedef pair<int, int> PII;
namespace DS{
    int v[MAX], sz[MAX];
    void init(int n){
        for(int i = 0 ; i < n ; i++)
            v[i] = i, sz[i] = 1;
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    int merge(int x, int y){
        x = find(x), y = find(y);
        v[x] = y;
        sz[y] += sz[x];
        sz[x] = 0;
        return sz[y];
    }
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    while(cin >> n >> m){
        vector<PII> v(m);
        vector<int> p;
        for(int i = 0 ; i < m ; i++){
            cin >> v[i].f >> v[i].s;
            p.push_back(v[i].f);
            p.push_back(v[i].s);
        }
        sort(p.begin(), p.end());
        p.resize(unique(p.begin(), p.end())-p.begin());
        DS::init(p.size());
        int ans = 1;
        for(int i = 0 ; i < (int)v.size() ; i++){
            int a = lower_bound(p.begin(), p.end(), v[i].f) - p.begin();
            int b = lower_bound(p.begin(), p.end(), v[i].s) - p.begin();
            ans = max(ans, DS::merge(a, b));
        }
        for(int i = 0 ; i < (int)p.size() ; i++){
            cout << DS::sz[i] << ' ';
        }
        cout << endl;
        cout << ans << endl;
    }
    return 0;
}
