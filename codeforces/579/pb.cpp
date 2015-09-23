#include <bits/stdc++.h>
using namespace std;
struct S{
    int s, a, b;
    S(){}
    S(int _s, int _a, int _b) : s(_s), a(_a), b(_b){}
    bool operator<(const S& _b) const {
        return s > _b.s;
    }
};
int ans[1024];
int main(){
    vector<S> s;
    int n;
    cin >> n;
    for(int i = 2 ; i <= 2 * n ; i++){
        for(int j = 1 ; j < i ; j++){
            int t;
            cin >> t;
            s.push_back(S(t, i, j));
        }
    }
    sort(s.begin(), s.end());
    for(int i = 0 ; i < (int)s.size() ; i++){
        if(ans[s[i].a] || ans[s[i].b]) continue;
        ans[s[i].a] = s[i].b;
        ans[s[i].b] = s[i].a;
    }
    for(int i = 1 ; i <= 2 * n ; i++)
        cout << ans[i] << ' ';
    cout << endl;
}
