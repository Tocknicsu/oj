#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a, b, c, s;
    cin >> a >> b >> c;
    s = a + b + c;
    s >>= 1;
    ll re = 1;
    re *= s;
    re *= (s-a);
    re *= (s-b);
    re *= (s-c);
    cout << re << endl;
    return 0;
}
