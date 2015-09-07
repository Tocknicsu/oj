#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& vec, vector<int>& ans, int m, int p = 0){
    if((int)ans.size() == m){
        for(int i = 0 ; i < (int)ans.size() ; i++){
            cout << ans[i] << ' ';
        }
        cout << endl;
        return;
    }
    if(p >= (int)vec.size())
        return;
    ans.push_back(vec[p]);
    dfs(vec, ans, m, p+1);
    ans.pop_back();
    dfs(vec, ans, m, p+1);
}

void Solve(int n){
    vector<int> vec(n), ans;
    for(int i = 0 ; i < n ; i++)
        cin >> vec[i];
    int m;
    cin >> m;
    sort(vec.begin(), vec.end());
    dfs(vec, ans, m);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    while(cin >> n, n){
        Solve(n);
        cout << endl;
    }
    return 0;
}
