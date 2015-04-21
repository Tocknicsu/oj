#include <bits/stdc++.h>
using namespace std;
#define INF 1029384756
int cost(string x, string y){
	if(x.size() != y.size())
		return INF;
	int diff = 0;
	for(int i = 0 ; i < (int)x.size() ; i++)
		diff += x[i] != y[i];
	return diff == 1 ? 1 : INF;
}
void Solve(){
	int m[256][256];
	vector<string> str;
	map<string, int> find;
	string tmp;
	while(cin >> tmp, tmp != "*"){
		find[tmp] = str.size();
		str.push_back(tmp);
	}
	for(int i = 0 ; i < (int)str.size() ; i++)
		for(int j = 0 ; j < (int)str.size() ; j++)
			m[i][j] = cost(str[i], str[j]);
	for(int k = 0 ; k < (int)str.size() ; k++)
		for(int i = 0 ; i < (int)str.size() ; i++)
			for(int j = 0 ; j < (int)str.size() ; j++)
				m[i][j] = min(m[i][j], m[i][k]+m[k][j]);

	getline(cin, tmp);
	while(getline(cin, tmp), tmp.size()){
		stringstream ss(tmp);
		string a, b;
		ss >> a >> b;
		cout << a << ' ' << b << ' ' << m[find[a]][find[b]] << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		Solve();
		if(t) cout << endl;
	}
}
