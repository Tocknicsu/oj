#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	deque<int> d[2];
	for(int i = 0 ; i < 2 ; i++){
		int x, y;
		cin >> x;
		for(int j = 0 ; j < x ; j++){
			cin >> y;
			d[i].push_front(y);
		}
	}
	int ans = 0, f = 0;
	while(ans < 200 && d[0].size() && d[1].size()){
		f = d[0].back() < d[1].back();
		d[f].push_front(d[f^1].back());
		d[f].push_front(d[f].back());
		d[f^1].pop_back();
		d[f].pop_back();
		ans++;
	}
	if(d[0].empty() || d[1].empty()){
		cout << ans << ' ' << (d[0].empty() ? 2 : 1) << endl;
	} else {
		cout << -1 << endl;
	}
}
