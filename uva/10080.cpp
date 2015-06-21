#include <bits/stdc++.h>
using namespace std;
#define MAX 128
typedef pair<double, double> COOR;
int n, m, s, v;
vector<int> ed[MAX];
int con1[MAX], con2[MAX];
bool v2[MAX];
bool bi(int x){
	for(auto &y : ed[x]){
		if(!v2[y]){
			v2[y] = true;
			if(con2[y] == -1 || bi(con2[y])){
				con2[y] = x; con1[x] = y;
				return true;
			}
		}
	}
	return false;
}
double dis(const COOR& a, const COOR &b){
	return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
void Solve(){
	memset(con1, -1, sizeof(con1));
	memset(con2, -1, sizeof(con2));
	for(int i = 0 ; i < 128 ; i++){
		ed[i].clear();
	}
	COOR a[128], b[128];
	for(int i = 0 ; i < n ; i++)
		cin >> a[i].first >> a[i].second;
	for(int i = 0 ; i < m ; i++)
		cin >> b[i].first >> b[i].second;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			if(dis(a[i], b[j]) <= s * v)
				ed[i].push_back(j);
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		memset(v2, false, sizeof(v2));
		ans += bi(i);
	}
	cout << n - ans << endl;
}
int main(){
	while(cin >> n >> m >> s >> v)
		Solve();
	return 0;
}
