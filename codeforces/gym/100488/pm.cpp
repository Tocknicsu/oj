#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int nm = n * m;
	cout << nm << endl;
	nm -= n;
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++)
			cout << nm - i * n + j + 1<< ' ';
	}
}
