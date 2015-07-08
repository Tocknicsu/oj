#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
bool col[9][9], sqr[9][9], row[9][9];
int t[9][9];
vector<PII> s;
int n, sn;
int to_sqr(int x, int y){
    return x / sn * sn + y / sn;
}
bool dfs(int p){
    if( p == (int)s.size() ){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(j) cout << ' ';
                cout << t[i][j];
            }
            cout << endl;
        }
        return true;
    }
    int x = s[p].first, y = s[p].second;
    for(int i = 1 ; i <= n ; i++){
        if(row[x][i-1] || col[y][i-1] || sqr[to_sqr(x, y)][i-1]) continue;
        row[x][i-1] = col[y][i-1] = sqr[to_sqr(x, y)][i-1] = 1;
        t[x][y] = i;
        if(dfs(p+1))
            return true;
        row[x][i-1] = col[y][i-1] = sqr[to_sqr(x, y)][i-1] = 0;
    }
    return false;
}
void Solve(){
    s.clear();
    n = sn * sn;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++)
            col[i][j] = row[i][j] = sqr[i][j] = 0;
    }
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++){
            cin >> t[i][j];
            if(t[i][j]){
                row[i][t[i][j]-1] = col[j][t[i][j]-1] = sqr[to_sqr(i, j)][t[i][j]-1] = 1;
            } else {
                s.push_back(PII(i, j));
            }
        }
    if(!dfs(0))
        cout << "NO SOLUTION" << endl;
}
int main(){
    bool first = true;
    while(cin >> sn){
        if(first) first = false;
        else cout << endl;
        Solve();
    }
}
