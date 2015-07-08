#include <bits/stdc++.h>
using namespace std;
#define INF 1029384756
map<int, int> up_map;
map<int, int> left_map;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    up_map[0] = INF;
    up_map[n] = 0;
    left_map[0] = INF;
    left_map[n] = 0;
    for(int i = 0 ; i < m ; i++){
        int x, y;
        string str;
        cin >> x >> y >> str;
        auto u_it = up_map.lower_bound(x);
        auto l_it = left_map.lower_bound(y);
        if(str[0] == 'U'){
            left_map[y] = x;
            left_map[u_it->second] = l_it->second;
            cout << y - u_it->second << endl;
        } else {
            up_map[x] = y;
            up_map[l_it->second] = u_it->second;
            cout << x - l_it->second << endl;
        }
    }
    return 0;
}
