#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll a, b, ans = 0;
	cin >> a >> b;
	while( a && b ){
		ans += a / b;
		a %= b;
		swap(a, b);
	}
	cout << ans << endl;
}
