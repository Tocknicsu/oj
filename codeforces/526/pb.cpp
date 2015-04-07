#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int node[4192];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	for(int i = 2, ed = pow(2, n+1) ; i < ed ; i++)
		cin >> node[i];
	ll ans = 0;
	for(int i = pow(2, n) - 1 ; i >= 1 ; i--){
		ans += abs(node[2*i] - node[2*i+1]);
		node[i] += max(node[2*i], node[2*i+1]);
	}
	cout << ans << endl;

}
