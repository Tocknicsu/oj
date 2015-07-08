#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
struct S{
    ll a, b;
    S(){}
    S(ll _a, ll _b) : a(_a), b(_b) {}
    S& operator+=(const S &s){
        a += s.a;
        b += s.b;
        return (*this);
    }
};
int main(){
    ll n;
    cin >> n;
    while(n--){
        S l(0, 1), r(1, 0), ans(1,1);
        string str;
        cin >> str;
        for(ll i = 0 ; str[i] ; ++i){
            if(str[i] == 'R'){
                l = ans;
                ans += r;
            } else {
                r = ans;
                ans += l;
            }
        }
        ll gcd = __gcd(ans.a, ans.b);
        cout << ans.a/gcd << '/' << ans.b/gcd << endl;
    }
}
