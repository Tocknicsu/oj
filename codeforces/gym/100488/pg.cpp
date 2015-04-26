#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n, s, m = 1;
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> s;
	vector<int> vec;
	for(int i = 0, tmp ; i < n ; i++){
		cin >> tmp;
		if( m * tmp > s) break;
		vec.push_back(tmp);
		m *= tmp;
	}
	int ans = 0;
	while(vec.size()){
		ans += s / m;
		s %= m;
		m /= vec.back();
		vec.pop_back();
	}
	cout << ans + s << endl;
}
