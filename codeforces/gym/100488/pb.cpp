#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	if(n == 1){
		cout << "A 1" << endl;
		return 0;
	}
	vector<int> q[128];
	int ans[128];
	for(int i = 0 ; i < (n+1) / 2 ; i++){
		cout << "Q " << i + 1 << " " << i + n/2 << endl;
		for(int j = 0 ; j < n / 2 ; j++){
			int tmp;
			cin >> tmp;
			q[i].push_back(tmp);
		}
		if(i){
			int f[128] = {0};
			for(int j = 0 ; j < (int)q[i-1].size() ; ++j)
				f[q[i-1][j]] = 1;
			for(int j = 0 ; j < (int)q[i].size() ; ++j)
				f[q[i][j]] -= 1;
			for(int j = 0 ; j < 128 ; j++)
				if(f[j] == 1)
					ans[i-1] = j;
				else if(f[j] == -1)
					ans[i+n/2 - 1] = j;
		}
	}
	{
		int f[128] = {0};
		for(int j = 0 ; j < (int)q[j].size() ; ++j)
			f[q[0][j]] += 1;
		for(int j = 0 ; j < (int)q[(n+1)/2-1].size() ; ++j)
			f[q[n/2-1][j]] += 1;
		for(int j = 0 ; j < 128 ; j++)
			if(f[j] == 2){
				ans[n/2 - 1] = j;
			}
	}
	{
		int f[128];
		fill(f, f+128, 1);
		for(int j = 0 ; j < n - 1 ; j++)
			f[ans[j]] -= 1;
		for(int j = 1 ; j <= n ; j++)
			if(f[j]) ans[n-1] = j;
	}
	cout << "A ";
	for(int i = 0 ; i < n ; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
