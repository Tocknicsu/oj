#include <bits/stdc++.h>
using namespace std;
#define ALL(v) v.begin(), v.end()
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	while(cin >> n){
		vector<int> num(n);
		for(int i = 0 ; i < n ; i++)
			cin >> num[i];
		sort(ALL(num));
		int l, r;
		if( n & 1 )
			l = r = num[n/2];
		else
			r = num[n/2], l = num[n/2-1];
		int count = upper_bound(ALL(num), r) - lower_bound(ALL(num), l);
		int ans = 1;
		if( !(n & 1) )
			ans = num[n/2] - num[n/2-1] + 1;
		cout << l << ' ' << count << ' ' << ans << endl;;
	}
}
