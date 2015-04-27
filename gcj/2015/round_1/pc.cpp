#include <bits/stdc++.h>
using namespace std;
#define INF 1029384756
typedef pair<int, int> PII;
double get(PII a){
	if(a.second == 0){
		if(a.first > 0)
			return INF;
		else
			return -INF;
	}
	return double(a.first) / double(a.second);
}
void Solve(int cases){
	cout << "Case #" << cases << ":" << endl;
	int n;
	cin >> n;
	vector<PII> point(n);
	vector<PII> slope[4096];
	for(int i = 0 ; i < n ; i++)
		cin >> point[i].first >> point[i].second;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			int x = point[i].first - point[j].first;
			int y = point[i].second - point[j].second;
			if(y==0) x = x > 0;
			if(x==0) y = 0;
			if(y<0) x *= -1, y *= -1;
			slope[i].push_back(PII(x, y));
		}
	}
	for(int i = 0 ; i < n ; i++){
		int up, down,ans = INF;
		for(int j = 0 ; j < n ; j++){
		up = down = 0;
			if( i == j ) continue;
			for(int k = 0 ; k < n ; k++){
				if(i == k) continue;
				if(slope[i][j] == slope[i][k]) continue;
				if(get(slope[i][j]) > get(slope[i][k])){
					if(point[k].first > point[i].first || point[k].second < point[i].second)
						down++;
					else
						up++;
				} else {
					if(point[k].first < point[i].first || point[k].second > point[i].second)
						up++;
					else
						down++;
				}
			}
			ans = min(ans, min(up, down));
		}
		cout << min(up, down) << endl;
	}
}
int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		Solve(i+1);
	return 0;
}
