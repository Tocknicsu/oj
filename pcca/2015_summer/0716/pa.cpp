#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, PII> PLI;

namespace DS{
    int v[10485776], sz;
    void init(int n){
        for(int i = 0 ; i < n ; i++)
            v[i] = i;
        sz = n;
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    int merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return 0;
        sz--;
        v[x] = y;
        return 1;
    }
};

int main(){
    int n;
    bool first = true;
    while(cin >> n){
        if(first) first = false;
        else cout << endl;
        ll ans = 0;
        ll a, b, c;
        for(int i = 0 ; i < n - 1 ; i++){
            cin >> a >> b >> c;
            ans += c;
        }
        cout << ans << endl;
        ans = 0;
        vector<PLI> ed;
        int m, k;
        cin >> m;
        for(int i = 0 ; i < m ; i++){
            cin >> a >> b >> c;
            ed.push_back(PLI(c, PII(a, b)));
        }
        cin >> k;
        for(int i = 0 ; i < k ; i++){
            cin >> a >> b >> c;
            ed.push_back(PLI(c, PII(a, b)));
        }
        sort(ed.begin(), ed.end());
        DS::init(n);
        for(int i = 0 ; i < (int)ed.size() ; i++)
            ans += DS::merge(ed[i].s.f-1, ed[i].s.s-1) * ed[i].f;
        cout << ans << endl;
    }
}
