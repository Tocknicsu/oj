#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct S{
    int a, b, c;
    S(){}
    S(int _a, int _b, int _c) : a(_a), b(_b), c(_c){}
    bool operator<(const S& b) const {
        return c < b.c;
    }
};
namespace DS{
    int v[131072], sz;
    void init(int n){
        for(int i = 0 ; i < n ; i++)
            v[i] = i;
        sz = n;
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    void merge(int x, int y){
        v[x] = y;
    }
};
int main(){
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        vector<S> s;
        DS::init(n);
        ll ans = 0;
        int sz = n;
        for(int i = 0 ; i < m ; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            s.push_back(S(a, b, c));
        }
        sort(s.begin(), s.end());
        for(int i = 0 ; sz != 1 && i < m ; i++){
            int x = DS::find(s[i].a);
            int y = DS::find(s[i].b);
            if(x != y){
                DS::merge(x, y);
                sz--;
                ans += s[i].c;
            }
        }
        cout << (sz == 1 ? ans : -1ll) << endl;
        
    }
    
}
