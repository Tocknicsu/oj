#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1048576], b[1048576];
int gcdEx(int a, int b, int &x, int &y){
	if(b==0) return x = 1, y = 0, a;
	int r, t;
	r = gcdEx(b, a%b, x, y);
	t = y, y = x - (a / b) * y, x = t;
	return r;
}
bool liner_equation(int a, int b, int c, int &x, int &y){
	int d = gcdEx(a, b, x, y);
	if(c % d) return false;
	int k = c / d;
	x *= k, y *= k;
	return true;
}
int main(){
	fill(a, a+1048576, -1);
	fill(b, b+1048576, -1);
	ll x1, h1, y1, x2, h2, y2, a1, a2, m;
	cin >> m;
	cin >> h1 >> a1;
	cin >> x1 >> y1;
	cin >> h2 >> a2;
	cin >> x2 >> y2;
	int t = 0;
	a[h1] = b[h2] = 0;
	while(h1 != a1){
		h1 = (x1 * h1 + y1) % m;
		if(a[h1] != -1) break;
		a[h1] = ++t;
	}
	cout << "OAO" << endl;
	ll a_loop = 1;
	while(h1 != a1){
		cout << h1 << endl;
		h1 = (x1 * h1 + y1) % m;
		a_loop++;
	}
	if(a[a1] == -1){
		cout << -1 << endl;
		return 0;
	}
	t = 0;
	cout << "XD" << endl;
	while(h2 != a2){
		h2 = (x2 * h2 + y2) % m;
		if(b[h2] != -1) break;
		b[h2] = ++t;
	}
	ll b_loop = 1;
	h2 = (x2 * h2 + y2) % m;
	while(h2 != a2){
		h2 = (x2 * h2 + y2) % m;
		b_loop++;
	}
	cout << "XD" << endl;
	if(b[a2] == -1){
		cout << "-1" << endl;
		return 0;
	}
	int x, y;
	if(liner_equation(a_loop, -b_loop, b[a2]-a[a1], x, y)){
		cout << a[a1] + x * a_loop << endl;
	} else {
		cout << -1 << endl;
	}
}
