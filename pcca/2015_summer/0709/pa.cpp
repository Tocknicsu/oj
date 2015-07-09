#include <bits/stdc++.h>
using namespace std;

int main(){
    double a, b;
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> a >> b;
    vector<double> v(2*a);
    for(int i = 0, a2 = 2 * a ; i < a2 ; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    
    cout << fixed << min(min(b, v[0]*3*a), v[a]/2*3*a) << endl;;
}
