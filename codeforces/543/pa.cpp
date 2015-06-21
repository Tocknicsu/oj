#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[512][512] = {};
int main(){
	ll n, m, b, mod;
	cin >> n >> m >> b >> mod;
	vector<int> num(n+1);
	for(int i = 1 ; i <= n ; i++) cin >> num[i];
	dp[0][0] = 1;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			for(int k = num[i] ; k <= b ; k++){
				dp[j][k] = (dp[j][k] + dp[j-1][k-num[i]]) % mod;
				
			}
		}
	}
	ll total = 0;
	for(int i = 0 ; i <= b ; i++)
		total = (total + dp[m][i]) % mod;
	cout << total << endl;
}

//[i][j][k] = [i][j][k] + [i-1][j-1][k-num[i]];
