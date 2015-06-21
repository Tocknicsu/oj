#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dfs(const ll n){
	if( n <= 9 )
		return n;
	ll re = 0;
	vector<int> vec;
	ll sn = n;
	ll tmp = 0;
	while(sn){
		vec.push_back(sn % 10);
		tmp = tmp * 10 + sn % 10;
		sn /= 10;
	}
	for(int i = 0 ; i < (int)vec.size() ; i++){
		re += pow(10, min(i, (int)vec.size()-i-1)) * vec[i];
	}
	if(tmp < n) re++;
	cout << (int)pow(10, vec.size() - 1) << endl;
	return re + dfs(pow(10, vec.size() - 1)-1);
}

void Solve(int cases){
	ll n;
	cin >> n;
	cout << "Case #" << cases << ": " << dfs(n) << endl;
}


int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		Solve(i+1);
	return 0;
}
