#include <bits/stdc++.h>
using namespace std;
#define MAX 262144
int p[MAX], so[MAX];
map<int, int> to;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> p[i];
        so[i] = p[i];
        to[p[i]] = i;
    }
    sort(p, p+n);
    while(m--){
        int s, l, flag = 1, ns, t = 0, ls = -1;
        cin >> s >> l;
        s = lower_bound(p, p+n, so[s-1]) - p;
        while(1){
            if(flag == 1){
                ns = upper_bound(p+s, p+n, p[s]+l) - p - 1;
            } else {
                ns = lower_bound(p, p+s, p[s]-l) - p;
            } 
            flag *= -1;
            l -= abs(p[ns] - p[s]);
            if(ns == s && t)
                break;
            if(ls == ns)
                l %= (abs(p[ns]-p[s]) * 2);
            ls = s;
            s = ns;
            ++t;
        }
        cout << to[p[s]] + 1 << endl;
    }
    return 0;
}
