#include <bits/stdc++.h>
using namespace std;

map<int, int> table;
void print(){
	for(map<int, int>::iterator it = table.begin() ; it != table.end() ; ++it)
		cout << it->first << ' ' << it->second << endl;
	cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<int> vec;
	for(int i = 0, tmp ; i < n ; i++){
		cin >> tmp;
		table[tmp] += 1;
		vec.push_back(tmp);
	}
	if(table.size() == 1){
		cout << 0 << endl;
		return 0;
	}
	int q;
	cin >> q;
	for(int i = 0 ; i < q ; i++){
		int p, c;
		cin >> p >> c;
		p--;
		table[vec[p]]--;
		table[c] += 1;
		vec[p] = c;
		if(table[c] == n){
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
