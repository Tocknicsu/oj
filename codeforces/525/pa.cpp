#include <bits/stdc++.h>
using namespace std;
map<int, int> key;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	char k, d;
	cin >> n;
	int ans = 0;
	for(int i = 1 ; i < n ; i++){
		cin >> k >> d;
		key[k]++;
		d = d - 'A' + 'a';
		if( key[d] ) 
			key[d]--;
		else
			ans++;
	}
	cout << ans << endl;
}
