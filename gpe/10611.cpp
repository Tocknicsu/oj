#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vec[2];

int main(){
	ll num = 0, flag = 0;
	for(int i = 1 ; i < 65536 * 2 ; i++){
		num += i;
		if( i & 1 ) flag ^= 1;
		vec[flag].push_back(num);
	}
	for(int i = 0 ; i < 2 ; i++){
		for(int j = 0 ; j < 10 ; j++)
			cout << vec[i][j] << ' ';
		cout << endl;
	}
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		if( i ) cout << endl;
		ll tmp;
		cin >> tmp;
		tmp = abs(tmp);
		flag = tmp & 1;
		ll p = lower_bound(vec[flag].begin(), vec[flag].end(), tmp) - vec[flag].begin();
		ll ans = ((p / 2) * 4) + (p & 1 ? 1 : 0) + (flag ? 0 : 2);
		cout << ans << endl;
	}
}

// 1 2 4 5
// 0
