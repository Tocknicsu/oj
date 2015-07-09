#include <bits/stdc++.h>
using namespace std;

int main(){
	int q, t, n;
	cin >> n;
	vector<int> x(n+1);
	for(int i = 1 ; i <= n ; i++){
		cin >> x[i];
		x[i] += x[i-1];
	}
	cin >> q;
	while(q--){
		cin >> t;
		cout << lower_bound(x.begin(), x.end(), t) - x.begin() << endl;
	}
	return 0;
}
