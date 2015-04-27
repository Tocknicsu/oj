#include <iostream>
using namespace std;

void Solve(int case_id){
	int n, ans = 0, total = 0, tmp;
	scanf("%d", &n);
	for(int i = 0 ; i <= n ; i++){
		scanf("%1d", &tmp);
		if( total < i ){
			ans += abs(total-i);
			total += abs(total-i);
		}
		total += tmp;
	}
	printf("Case #%d: %d\n", case_id, ans);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)
		Solve(i+1);
}
