#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, tmp;
    cin >> n;
    vector<int> ans;
    int Max = 0;
    map<int, int> m;
    for(int i = 0 ; i < n ; i++){
        cin >> tmp;
        m[tmp]++;
        if(m[tmp] > Max){
            Max = m[tmp];
            ans.clear();
        }
        if(m[tmp] == Max){
            ans.push_back(tmp);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0 ; i < (int)ans.size() ; i++){
        cout << ans[i] << ' ' << Max << endl;

    }
}
