#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009
typedef long long ll;
int main(){
	ll num[1024] = {0};
	num[0] = num[1] = 1;
	num[2] = 2;
	for(int i = 3 ; i <= 1000 ; i++){
		num[i] = 2 * num[i-2] + num[i-1] + 1;
		num[i] %= MOD;
	}
	int n;
	while(cin >> n, n)
		cout << num[n] << endl;
}
