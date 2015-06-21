#include <bits/stdc++.h>
using namespace std;


int cost[5];

void calc(int r, int w){
	fill(cost, cost+5, 0);
	if( r > w ) swap(r, w);
	if( r == 1 ){
		if(w == 1){
			cost[0] = 1;
			return;
		}
		cost[1] = 2;
		cost[2] = w - 2;
	} else {
		cost[2] = 4;
		cost[3] =2 * ( r + w ) - 8;
		cost[4] = r * w - cost[2] - cost[3];
	}
}
void print(){
	for(int i = 0 ; i < 5 ; i++)
		cout << cost[i] << ' ';
	cout << endl;
}
void Solve(int cases){
	int ans = 0;
	int r, w, n;
	cin >> r >> w >> n;
	calc(r, w);
	int now = r * w - n, x = 4;
		print();
	while(now){
		int tmp = min(now, cost[x] / (x + 1) + cost[x] % (x+1));
		now -= tmp;
		cost[x] -= tmp;
		int de = tmp * x;
		for(int i = x ; i >= 0 && de ; i--){
			int r = min(de, cost[i]);
			cost[i] -= r;
			if(i)
				cost[i-1] += r;
			de -= r;
		}
		x--;
		print();
	}
	for(int i = 0 ; i < 5 ; i++)
		ans += cost[i] * i;
	if(ans & 1)
		cout << "=============gg================" << endl << endl;
	cout << "Case #" << cases << ": " << ans / 2 << endl;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		Solve(i+1);
	return 0;
}
