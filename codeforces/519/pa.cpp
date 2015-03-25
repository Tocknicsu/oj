#include <bits/stdc++.h>
using namespace std;
map<int, int> val;
bool up(char c){
	return c >= 'A' && c <= 'Z';
}
int main(){
	val['q'] = 9, val['r'] = 5, val['b'] = 3, val['n'] = 3, val['p'] = 1;
	string str;
	int b, w;
	b = w = 0;
	for(int i = 0 ; i < 8 ; i++){
		cin >> str;
		for(int j = 0 ; j < 8 ; j++){
			if( !isalpha(str[j] ) ) continue;
			if( up(str[j]) ) w += val[str[j]-'A'+'a'];
			else b += val[str[j]];
		}
	}
	if( b > w ) cout << "Black" << endl;
	else if( w > b ) cout << "White" << endl;
	else cout << "Draw" << endl;
	return 0;
}
