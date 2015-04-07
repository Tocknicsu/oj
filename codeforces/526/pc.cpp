#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, va, vb, ca, cb;
ll calc(int c_a){
	if( c_a * ca > t ) return 0;
	ll re = c_a * va;
	ll r = t - c_a * ca;
	re += vb * (r / cb);
	return re;
}
int main(){
	cin >> t >> va >> vb >> ca >> cb;
	ll ans = 0, ans_c_a = 0;
	ll lcm = ca / __gcd(ca, cb) * cb;
	ll pre_ans = max( lcm / ca * va, lcm / cb * vb);
	t %= lcm;
	ll l = 0, r = t / ca + 1;
	while( l + 3 < r ){
		ll m1 = (l * 2 + r ) / 3;
		ll m2 = (l + 2 * r ) / 3;
		ll t1 = calc(m1);
		ll t2 = calc(m2);
		if( t1 < t2 ){
			l = m1;
		} else {
			r = m2;
		}
	}
	for(int i = l ; i <= r ; i++){
		ans = max(ans, calc(i));
	}
	cout << ans + pre_ans << endl;
}
