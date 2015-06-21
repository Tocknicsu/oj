#include <bits/stdc++.h>
using namespace std;
const int MAX = 131072 * 4;
int node[MAX];
void build(){
	for(int i = MAX / 2 - 1 ; i > 0 ; i--)
		node[i] = min(node[i*2], node[i*2+1]);
}
int query(){
}
int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> node[MAX / 2 + i];
	build();

}
