#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    for(int i = 0 ; i < n ; i++){
        ll Min = 2147483647;
        if(i != 0)
            Min = min(Min, abs(v[i]-v[i-1]));
        if(i != n - 1)
            Min = min(Min, abs(v[i]-v[i+1]));
        ll Max = max(abs(v[i]-v[0]), abs(v[i]-v[n-1]));
        cout << Min << ' ' << Max << endl;
    }
}
