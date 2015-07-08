#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
double p, a, b, c, d, n, ans;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> p >> a >> b >> c >> d >> n;
    vector<double> v(n), tmp(n);
    tmp[0] = -1029348576;
    for(int i = 1 ; i <= n ; i++){
        v[i] = p * (sin(a * double(i) + b) + cos(c * double(i) + d) + 2);
        cout << v[i] << endl;
        tmp[i] = v[i] > v[i-1] ? 0 : tmp[i-1] + v[i] - v[i-1];
        ans = max(ans, tmp[i]);
    }
    cout << ans << endl;
    return 0;
}
