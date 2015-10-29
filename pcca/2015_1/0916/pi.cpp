#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    vector<int> l(n), r(n);
    l[0] = v[0];
    r[n-1] = v[n-1];
    for(int i = 1 ; i < n ; i++)
        l[i] = max(v[i], l[i-1]);
    for(int i = n - 2 ; i >= 0 ; i--)
        r[i] = min(v[i], r[i+1]);
    int ans = 0;
    for(int i = 1 ; i < n - 1 ; i++)
        if(l[i-1] < v[i] && v[i] < r[i+1])
            ans++;
    if(v[0] < r[1])
        ans++;
    if(l[n-2] < v[n-1])
        ans++;
    cout << ans << endl;

    return 0;
}
