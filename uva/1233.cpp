#include <bits/stdc++.h>
using namespace std;
#define MAX 512
#define INF 1029384756
#define f first
#define s second
typedef pair<int, int> PII;
void Solve(){
	int n, m;
	int dis[MAX];
	int tmp_n;
	vector<PII> ed[MAX];
	priority_queue<PII, vector<PII>, greater<PII> > PQ;
	cin >> n >> m;
	cin >> tmp_n;
	for(int i = 0 ; i < tmp_n ; i++){
		int tmp;
		cin >> tmp;
		PQ.push(PII(0, tmp));
	}
	fill(dis, dis+MAX, INF);
	for(int i = 1 ; i <= m ; i++){
		cin >> tmp_n;
		for(int j = 0 ; j < tmp_n ; j++){
			int d, x;
			cin >> d >> x;
			ed[i].push_back(PII(d, x));
		}
	}
	while(PQ.size()){
		PII now = PQ.top(); PQ.pop();
		if( dis[now.s] < now.f ) continue;
		for(int i = 0 ; i < ed[now.s].size() ; i++){
			if( now.f + ed[now.s][i].f < dis[ed[now.s][i].s]){
				dis[ed[now.s][i].s] = now.f + ed[now.s][i].f;
				if(ed[now.s][i].s)
					PQ.push(PII(dis[ed[now.s][i].s], ed[now.s][i].s));
			}
		}
	}
	int ans = 0, tmp = 0;
	while(tmp + dis[0] < n){
		ans++;
		tmp += dis[0] - 1;
	}
	cout << ans << endl;
}
int main(){
	int n;
	cin >> n;
	while(n--)
		Solve();
}
