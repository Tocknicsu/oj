#include <bits/stdc++.h>
using namespace std;
int x[2048], v[2048], n, ans;
int dfs(int u){
	if(v[u]) return v[u];
	if(x[u] == -1) return v[u] = 1;
	return v[u] = dfs(x[u]) + 1;
}
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> x[i];
	for(int i = 1 ; i <= n ; i++) ans = max(ans, dfs(i));
	cout << ans << endl;
	return 0;
}
