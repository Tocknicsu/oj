#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(int n, ll m){
    vector<int> v(n);
    int l = 0, r = n - 1;
    ll x = 1;
    m--;
    for(int i = 0 ; i < n - 2 ; i++)
        x *= 2;
    for(int i = 1 ; i < n ; i++){
        if(m >= x){
            m -= x;
            v[r--] = i;
        } else {
            v[l++] = i;
        }
        x /= 2;
    }
    v[l] = n;
    for(int i = 0 ; i < n ; i++)
        cout << v[i] << ' ';
    cout << endl;
}
int main(){
    ll n, m;
    while(cin >> n >> m)
        Solve(n, m);
}
