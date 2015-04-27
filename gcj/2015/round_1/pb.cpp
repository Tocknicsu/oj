#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vec;
typedef pair<ll, ll> PII;
PII guess(ll t){
	PII re = PII(0, 0);
	for(ll i = 0 ; i < int(vec.size()) ; i++){
		re.first += (t-1) / vec[i];
		re.second += t % vec[i] == 0;
	}
	if( t > 0 )
		re.first += vec.size();
	return re;
}
void Solve(ll cases){
	ll n, m;
	cin >> n >> m;
	vec = vector<ll>(n);
	for(ll i = 0 ; i < n ; i++)
		cin >> vec[i];
	ll time = 0, step = 1029384756ll * 1048576ll;
	while(step){
		PII tmp = guess(time + step);
		if(tmp.first + tmp.second >= m)
			step >>= 1;
		else
			time += step;
	}
	ll ans = guess(time).first + guess(time).second;
	time += 1;
	for(int i = 0 ; i < int(vec.size()) ; i++){
		if(!( time % vec[i] )){
			ans++;
			if(ans == m){
				cout << "Case #" << cases << ": " << i+1 << endl;
				break;
			}
		}
	}
	
}
int main(){
	ll n;
	cin >> n;
	for(ll i = 0 ; i < n ; i++)
		Solve(i+1);
	return 0;
}
