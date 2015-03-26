#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
ld L, R;
ld str2dou(string str){
	ld re;
	stringstream ss(str);
	ss >> re;
	return re;
}
string a, b;
int p;
ld ans;
void DFS(ld now){
	if( b[p] == '(' ){
		ld l, r;
		p += 3;
		DFS(now*L);
		p += 1;
		DFS(now*R);
		p += 1;
	} else if( b[p] == '1' ){
		p+=1;
		ans+=now;
	} else if( b[p] == '0' ){
		p += 1;
	}
}
int main(){
	while(cin >> a >> b, !(a==b && a=="0") ){
		ans = 0;
		p = 0;
		L = str2dou(a);
		R = 1.0 - L;
		swap(L, R);
		DFS(1);
		cout << fixed << setprecision(6) << ans << endl;
	}
}
