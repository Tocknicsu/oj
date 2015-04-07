#include <bits/stdc++.h>
using namespace std;
string str;
int n;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> str;
	bool ok = false;
	for(int i = 0 ; i < n ; i++){
		for(int j = 1 ; j <= n / 4 && i + 4 * j < n ; j++){
			if( str[i] == '*' && str[i+j] == '*' && str[i+2*j] == '*' && str[i+3*j] == '*' && str[i+4*j] == '*')
				ok = true;
		}
	}
	if(ok) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}
