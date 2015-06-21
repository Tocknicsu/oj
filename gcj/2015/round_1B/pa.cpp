#include <bits/stdc++.h>
using namespace std;
const int MAX = 1048576;
int dp[MAX];
int trans(int x){
	int re = 0;
	while(x){
		re = re * 10 + x % 10;
		x /= 10;
	}
	return re;
}
int main(){
	dp[1] = 1;
	queue<int> Q;
	Q.push(1);
	while(Q.size()){
		int now = Q.front();
		Q.pop();
		int b = now + 1;
		if(b < MAX && b > 0){
			if(!dp[b]){
				dp[b] = dp[now] + 1;
				Q.push(b);
			}
		}
		b = trans(now);
		if(b < MAX && b > 0){
			if(!dp[b]){
				dp[b] = dp[now] + 1;
				Q.push(b);
			}
		}
	}
	for(int i = 0 ; i < 100 ; i++)
		cout << i * 100 << ' ' << dp[i*100] << endl;
	int q;
	cin >> q;
	for(int i = 1 ; i <= q ; i++){
		int tmp;
		cin >> tmp;
		cout << "Case #" << i << ": " << dp[tmp] << endl;
	}
}
