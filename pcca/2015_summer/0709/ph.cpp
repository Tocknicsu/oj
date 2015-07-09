#include <bits/stdc++.h>
using namespace std;
#define INF 1029384756
typedef pair<int, int> PII;
int main(){
    int n, min_cost = INF, cost = 0;
    cin >> n;
    vector<PII> v(n);
    vector<int> c(256);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i].first;
    for(int i = 0 ; i < n ; i++){
        cin >> v[i].second;
        cost += v[i].second;
    }
    sort(v.begin(), v.end());
    int pos = 0;
    while(pos < (int)v.size()){
        int num = upper_bound(v.begin()+pos, v.end(), PII(v[pos].first, INF)) - v.begin() - pos;
        int now_cost = cost;
        int need = pos - num + 1;
        for(int i = 1 ; need > 0 ; i++){
            int r = min(need, c[i]);
            need -= r;
            now_cost += r * i;
        }
        for(int i = pos, end = pos + num ; i < end ; i++){
            now_cost -= v[i].second;
            cost -= v[i].second;
            c[v[i].second]++;
        }
        min_cost = min(min_cost, now_cost);
        pos += num;
    }
    cout << min_cost << endl;
    return 0;
}
