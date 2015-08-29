#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool ok(int x, int start = 0){
    int now = 0;
    int pos = start;
    for( ; pos < (int)v.size() && now < x ; pos++){
        if(v[pos] > now) now++;
        else now = v[pos];
    }
    if(now != x)
        return false;
    now--;
    while(now && pos < (int)v.size()){
        if(v[pos] < now)
            return ok(x, pos-v[pos]+1);
        now--;
        pos++;
    }
    if(now)
        return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    v = vector<int>(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    int ans = 0, step = n;
    while(step){
        if(ok(ans+step)){
            ans += step;
        } else {
            step >>= 1;
        }
    }
    cout << ans << endl;
    return 0;
}
