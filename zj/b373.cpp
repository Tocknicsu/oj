#include <bits/stdc++.h>
using namespace std;
namespace BIT{
    const int MAX = 16384;
    int v[MAX];
    void init(){
        for(int i = 0 ; i < MAX ; i++)
            v[i] = 0;
    }
    void add(int x){
        for(int i = x ; i < MAX ; i += (i&-i))
            v[i] += 1;
    }
    int query(int x){
        int re = 0;
        for(int i = x ; i > 0 ; i -= (i&-i))
            re += v[i];
        return re;
    }
};
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    BIT::init();
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    int ans = 0;
    for(int i = n - 1 ; i >= 0 ; i--){
        ans += BIT::query(v[i]);
        BIT::add(v[i]);
    }
    cout << ans << endl;

    return 0;
}
