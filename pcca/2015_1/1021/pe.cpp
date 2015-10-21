#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> PIS;
map<string, PIS> m;
int dp[512][2048];
int done[512];
string start, query;
void dfs(string str){
    int node = m[str].first;
    if(done[node]) return;
    done[node] = true;
    stringstream ss(m[str].second);
    string v1, v2, tra;
    ss >> v1;
    if('A' <= v1[0] && v1[0] <= 'Z'){
        ss >> tra >> v2;
        dfs(v1); dfs(v2);
        int node_1 = m[v1].first, node_2 = m[v2].first;
        for(int i = 0 ; i < (int)query.size() ; i++){
            dp[node][i] = dp[node_1][i];
            if(dp[node][i] == (int)query.size()) continue;
            dp[node][i] = dp[node_2][dp[node][i]];
        }
    } else {
        for(int i = 0 ; i < (int)query.size() ; i++){
            dp[node][i] = i;
            for(int j = 0 ; j < (int)v1.size() ; j++){
                if(query[dp[node][i]] == v1[j])
                    dp[node][i]++;
                if(dp[node][i] >= (int)query.size())
                    break;
            }
        }
    }
}
void Solve(){
    memset(done, 0, sizeof(done));
    m.clear();
    int n;
    cin >> n;
    string buf;
    string str, tra, content;
    for(int i = 0 ; i < n ; i++){
        cin >> str >> tra;
        getline(cin, content);
        m[str] = PIS(i, content);
    }
    cin >> start >> query;
    dfs(start);
    /*
    for(auto x : m){
        cout << x.first << endl;
        for(int i = 0 ; i < (int)query.size() ; i++)
            cout << dp[x.second.first][i] << ' ';
        cout << endl;
    }
    */
    cout << (dp[m[start].first][0] == (int)query.size() ? "YES" : "NO") << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--)
        Solve();
    return 0;
}
