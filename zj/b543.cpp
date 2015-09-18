#include <bits/stdc++.h>
using namespace std;
struct S{
    int l, a, d;
};
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        bool d[8192];
        memset(d, 0, sizeof(d));
        int n, start;
        cin >> n;
        vector<S> s(n);
        for(int i = 0 ; i < n ; i++){
            cin >> s[i].l >> s[i].a >> s[i].d;
        }
        cin >> start;
        start--;
        queue<int> Q;
        Q.push(start);
        d[start] = true;
        int ans = 0;
        while(Q.size()){
            ans++;
            int t = Q.front(); Q.pop();
            for(int i = 0 ; i < n ; i++){
                if(!d[i] && s[i].l < s[t].l && s[i].d < s[t].a){
                    Q.push(i);
                    d[i] = true;
                }

            }
        }
        cout << ans << endl;
    }
}
