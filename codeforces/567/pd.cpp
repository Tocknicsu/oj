#include <bits/stdc++.h>
using namespace std;
int calc(int l, int r, int k){
    int x = r - l - 1;
    int y = x / (k+1);
    return y * (k+1) + k <= x ? y+1 : y;
}
int main(){
    set<int> r;
    int n, k, a, m;
    cin >> n >> k >> a >> m;
    r.insert(0);
    r.insert(n+1);
    int now = calc(0, n+1, a);
    for(int i = 0 ; i < m ; i++){
        int t;
        cin >> t;
        auto x = r.lower_bound(t);
        if(*x != t) --x;
        else continue;
        auto y = r.lower_bound(t);
        now -= calc(*x, *y, a);
        now += calc(*x,  t, a);
        now += calc( t, *y, a);
        if(now < k){
            cout << i+1 << endl;
            return 0;
        }
        r.insert(t);
    }
    cout << -1 << endl;
    return 0;
}
