#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
vector<int> v;
int n, m;
bool ok(int s){
	int use = 0, now = 0;
	while(use < m && now < (int)v.size()){
		now = upper_bound(v.begin()+now, v.end(), v[now]+s) - v.begin();
		use++;
	}
	return now == (int)v.size();
}
void Solve(){
	cin >> m >> n;
	v = vector<int>(n);
	for(int i = 0 ; i < n ; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int r, s;
	r = s = v[n-1] - v[0];
	while(s){
		if(ok(r-s)) r -= s;
		else s >>= 1;
	}
	cout << fixed << setprecision(1) << (double)(r)/2.0 << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--)
		Solve();
	return 0;
}
