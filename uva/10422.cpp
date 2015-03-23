#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, int, int> tlii;
map<ll, int> m;
int endstate[5][5] = {	2, 2, 2, 2, 2,
						1, 2, 2, 2, 2,
						1, 1, 0, 2, 2,
						1, 1, 1, 1, 2,
						1, 1, 1, 1, 1
					};
int now[5][5];
int d[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};
bool eql(){
	for(int i = 0 ; i < 5 ; i++)
		for(int j = 0 ; j < 5 ; j++)
			if( endstate[i][j] != now[i][j] )
				return false;
	return true;
}
ll encode(){
	ll re = 0;
	for(int i = 0 ; i < 5 ; i++)
		for(int j = 0 ; j < 5 ; j++)
			re = re * 3 + now[i][j];
	return re;
}
void decode(ll val){
	for(int i = 4 ; i >= 0 ; i--)
		for(int j = 4 ; j >= 0 ; j--)
			now[i][j] = val % 3, val /= 3;
}
void Solve(){
	string str[5];
	int sx, sy;
	for(int i = 0 ; i < 5 ; i++){
		getline(cin, str[i]);
		for(int j = 0 ; j < 5 ; j++){
			now[i][j] = ( str[i][j] == ' ' ? 0 : str[i][j] - '0' + 1 );
			if( ! now[i][j] ) sx = i, sy = j;
		}
	}
	queue< tlii > Q;
	Q.push( tlii(encode(), sx, sy) );
	while(Q.size()){
		tlii tmp = Q.front(); Q.pop();
		ll code = get<0>(tmp);
		int x = get<1>(tmp), y = get<2>(tmp);
		decode(code);
		if( eql() ){
			cout << "Solvable in " << m[code] << " move(s).";
			return;
		}
		if(m[code] >= 10) continue;
		for(int k = 0 ; k < 8 ; k++){
			int nx = x + d[k][0], ny = y + d[k][1];
			if( nx < 0 || nx > 4 || ny < 0 || ny > 4 ) continue;
			swap( now[x][y], now[nx][ny] );
			ll en = encode();
			if( ! m[en] ){
				m[en] = m[code] + 1;
				Q.push( tlii(en, nx, ny) );
			}
			swap( now[x][y], now[nx][ny] );
		}

	}
	cout << "Unsolvable in less than 11 move(s).";
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	string tmp;
	getline(cin, tmp);
	bool first = true;
	while(t--){
		if(first) first = false;
		else cout << endl;
		Solve();
	}
}
