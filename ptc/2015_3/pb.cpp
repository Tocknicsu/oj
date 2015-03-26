#include <bits/stdc++.h>
using namespace std;
void Solve(int n){
	int l, r;
	cin >> l >> r;
	vector<int> pack(r+1);
	vector<int> num;
	for(int i = 0 ; i < n ; i++){
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	for(int i = 0 ; i < num.size() ; i++)
		if( l <= num[i] && num[i] <= r ){
			cout << "YES" << endl;
			return;
		}
	pack[0] = 1;
	for(int i = 0 ; i < num.size() ; i++){
		for(int j = r ; j >= num[i] ; j--){
			if( pack[j - num[i]] )
				pack[j] = 1;
			if( pack[j] && l <= j && j <= r ){
				cout << "YES" << endl;
				return;
			}
		}
	}
	cout << "NO" << endl;
	return;
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	while(cin >> n, n){
		Solve(n);
	}
}
