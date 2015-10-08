#include <bits/stdc++.h>
using namespace std;

void Solve(){
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<int> v;
    int tmp;
    map<int, int> m;
    while(ss >> tmp){
        v.push_back(tmp);
        m[tmp] = v.size();
    }
    int ans = 0;
    for(map<int,int>::iterator t = m.begin() ; t != m.end() ; ++t)
        ans += (*t).second;
    cout << ans << endl;
}

int main(){
//    freopen("pa.in", "r", stdin);
    int n;
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    string str;
    getline(cin, str);
    while(n--)
        Solve();
    return 0;
}
