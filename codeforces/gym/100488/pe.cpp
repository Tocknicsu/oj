#include <bits/stdc++.h>
using namespace std;


char str[1048576];
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int alpha[26] = {0};
	cin >> str;
	int len = strlen(str);
	int halflen = len / 2;
	if(len & 1){
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 0 ; i < len ; i++){
		int p = str[i] - 'a';
		alpha[p]++;
		if(alpha[p] > halflen){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}
