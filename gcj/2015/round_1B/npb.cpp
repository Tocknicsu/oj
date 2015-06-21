#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
int cost[17][17];
bool use[17][17];

void calc(int r, int w){
	memset(use, 0, sizeof(use));
	memset(cost, 0, sizeof(cost));
	if(r == 1){
	} else {
		for(int i = 0 ; i < r ; i++)
			for(int j = 0 ; j < w ; j++){
				if(!i || !j)
					cost[i][j] = 3;
				else
					cost[i][j] = 4;
			}
	}
}
void Solve(int cases){
	int ans = 0;
	int r, w, n;
	cin >> r >> w >> n;
	if(r > w) swap(r, w);
	calc(r, w);
	cout << "Case #" << cases << ": " << ans / 2 << endl;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		Solve(i+1);
	return 0;
}
