#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
ll m[5][5] = {
	0, 0, 0, 0, 0,
	0, 1, 2, 3, 4,
	0, 2,-1, 4,-3,
	0, 3,-4,-1, 2,
	0, 4, 3,-2, -1
};
ll pen(int x){
	return x > 0 ? 1 : - 1;
}
ll mpow(ll x, ll n){
	ll t = x;
	ll now = 1;
	while(n){
		if(n & 1){
			now = m[abs(now)][abs(t)] * pen(now) * pen(t);
		}
		t = m[abs(t)][abs(t)];
		n >>= 1;
	}
	return now;
}

void Solve(int case_id){

	string str;
	ll l, x;
	cin >> l >> x >> str;
	ll now = 1;
	for(int i = 0 ; i < str.size() ; i++){
		now = m[abs(now)][str[i]-'i'+2] * pen(now);
	}
	if( mpow(now, x) != -1){
		cout << "Case #" << case_id << ": NO" << endl;
		return;
	}
	ll len = str.size() * x;
	str += str;
	str += str;
	now = 1;
	ll min_i = -1, min_k = -1;
	bool flag = true;
	for(int i = 0 ; i < str.size() ; i++){
		now = m[abs(now)][str[i]-'i'+2] * pen(now);
		if(now == 2){
			min_i = i + 1;
			break;
		}
	}
	now = 1;
	for(int i = str.size()-1 ; i >= 0 ; i--){
		now = m[str[i]-'i'+2][abs(now)] * pen(now);
		if(now == 4){
			min_k = str.size() - i;
			break;
		}
	}
	if(min_i == -1 || min_k == -1){
		flag = false;
	}
	if( len <= min_i + min_k )
		flag = false;
	cout << "Case #" << case_id << ": " << (flag ? "YES":"NO") << endl;
}
int main(){
	int n;
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		Solve(i+1);
	return 0;
}
