#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<double, double> PDD;
double calc(PDD a, PDD b, PDD c){
    double res = 0;
    res += a.f * b.s + b.f * c.s + c.f * a.s;
    res -= b.f * a.s + c.f * b.s + a.f * c.s;
    return abs(res / 2.0);
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<PDD> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i].f >> v[i].s;
    double ans = 0;
    for(int i = 0 ; i < n ; i++)
        for(int j = i + 1 ; j < n ; j++)
            for(int k = j + 1 ; k < n ; k++){
                ans = max(ans, calc(v[i], v[j], v[k]));
            }
    cout << fixed << setprecision(6) << ans << endl;
    
    return 0;
}
