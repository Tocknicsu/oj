#include <bits/stdc++.h>
using namespace std;
#define MAX 5005
#define INF 1029384756
map<int, int> m;
int v[MAX];
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, k, tmp;
	cin >> n >> k;
	for( int i = 0 ; i < n ; i++ ){
		cin >> v[i];
		for( int j = 1 ; j <= k ; j++ ){
			tmp = v[i] * j;
			if(m[tmp]) m[tmp] = min(m[tmp], j);
			else m[tmp] = j;
		}
	}
	int q;
	cin >> q;
	while( q-- ){
		int ans = INF;
		int x;
		cin >> x;
		for( int i = 0 ; i < n ; i++ ){
			for(int j = 1 ; j <= k ; j++){
				if(v[i] * j == x || m[x-v[i]*j])
					ans = min(ans, j + m[x-v[i]*j]);
			}
		}
		cout << ( ans > k ? -1 : ans ) << endl;
	}
}
