#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<PII> vec;
    vec.push_back(PII(1, n));
    for(int i = 0 ; i < m ; i++){
        int l, r;
        cin >> l >> r;
        int now = 0;
        for(int j = 0 ; j < (int)vec.size() ; j++){
            if(now + vec[j].second - vec[j].first + 1 >= l)
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while(n--)
        Solve();
    return 0;
}
