#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, Min;
vector<ll> num;
bool check(ll guess){
	if( guess < Min ) return false;
	ll tmp = 0, group = 1;
	for(int i = 0 ; i < n ; i++){
		if( tmp + num[i] > guess ){
			group += 1;
			tmp = num[i];
		} else tmp += num[i];
	}
	return group <= k;
}
int main(){
	while( cin >> n >> k ){
		num.clear();
		ll ans = 0, tmp;
		Min = 0;
		for( int i = 0 ; i < n ; i++ ){
			cin >> tmp;
			num.push_back( tmp );
			ans += tmp;
			Min = max( Min, tmp );
		}
		ll step = ans >> 1;
		while( step ){
			if( check( ans - step ) ) ans -= step;
			else step >>= 1;
		}
		cout << ans << endl;
	}
}
