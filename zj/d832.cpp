#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        vector<int> v(n), lmax(n), rmax(n);
        for(int i = 0 ; i < n ; i++)
            cin >> v[i];
        int now = 0;
        for(int i = 0 ; i < n ; i++){
            now += v[i];
            now = max(0, now);
            if(i)
                lmax[i] = max(now, lmax[i-1]);
            else
                lmax[i] = now;
        }
        now = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            now += v[i];
            now = max(0, now);
            if(i != n-1)
                rmax[i] = max(now, rmax[i+1]);
            else
                rmax[i] = now;
        }
        int ans = 0;
        for(int i = 0 ; i < n - 1 ; i++)
            ans = max(ans, lmax[i]+rmax[i+1]);
        cout << ans << endl;
    }
    return 0;
}
