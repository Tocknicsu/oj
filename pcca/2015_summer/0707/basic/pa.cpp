#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
double p, a, b, c, d, n, ans;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    while(cin >> p >> a >> b >> c >> d >> n){
        vector<double> v;
        for(int i = 1 ; i <= n ; i++)
            v.push_back(p * (sin(a * double(i) + b) + cos(c * double(i) + d) + 2));
        double ans = 0;
        int l = 0;
        for(int i = 1 ; i < n ; i++){
            if(v[i] > v[l]){
                l = i;
            } else {
                ans = max(ans, v[l] - v[i]);
            }
        }
        cout << fixed << setprecision(6) << ans << endl;
    }
    return 0;
}
