#include <bits/stdc++.h>
using namespace std;
void Solve(int cases){
	int n;
	cin >> n;
	vector<int> vec(n);
	int a = 0, b = 0, max_b = 0;
	for(int i = 0 ; i < n ; i++){
		cin >> vec[i];
	}
	for(int i = 1 ; i < n ; i++){
		if( vec[i] < vec[i-1] ){
			a += vec[i-1] - vec[i];
			max_b = max(vec[i-1] - vec[i], max_b);
		}
	}
	for(int i = 0 ; i < n - 1 ; i++)
		if(vec[i] > max_b)
			b += max_b;
		else
			b += vec[i];

	cout << "Case #" << cases << ": " << a << ' ' << b << endl;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		Solve(i+1);
	return 0;
}

