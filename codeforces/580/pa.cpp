#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    int ans = 0;
    int l = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
        if(i && v[i-1] > v[i])
            l = i;
        ans = max(ans, i - l + 1);
    }
    cout << ans << endl;
    return 0;
}
