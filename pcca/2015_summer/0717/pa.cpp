#include <iostream>
#include <queue>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void Solve(int m, int n){
	int t[32][32];
	string str;
	queue<PII> q;
	for(int i = 0 ; i < n ; i++){
		cin >> str;
		for(int j = 0 ; j < m ; j++){
			t[i][j] = str[j] == '.';
			if(str[j] == '@')
				q.push(PII(i, j));
		}
	}
	int ans = 0;
	while(q.size()){
		ans++;
		int x = q.front().f, y = q.front().s; q.pop();
		for(int i = 0 ; i < 4 ; i++){
			int nx = x + d[i][0];
			int ny = y + d[i][1];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(!t[nx][ny]) continue;
			t[nx][ny] = 0;
			q.push(PII(nx, ny));
		}
	}
	cout << ans << endl;
}
int main(){
	int n, m;
	while(cin >> n >> m, n || m)
		Solve(n, m);
}
