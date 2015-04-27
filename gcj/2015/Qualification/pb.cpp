#include <bits/stdc++.h>
using namespace std;

void Solve(int case_id){
	int cost = 1029384756;
	int n, max_pie = 0;
	cin >> n;
	vector<int> pie;
	for(int i = 0 ; i < n ; i++){
		int tmp;
		cin >> tmp;
		pie.push_back(tmp);
		max_pie = max(max_pie, tmp);
	}
	for(int i = 1 ; i <= max_pie ; i++){
		int tmp_cost = i;
		for(int j = 0 ; j < n ; j++){
			if(pie[j] > i){
				tmp_cost += (pie[j] / i) - (pie[j]%i==0);
			}
		}
		cost = min(cost, tmp_cost);
	}
	cout << "Case #" << case_id << ": " << cost << endl;
}

int main(){
	int n;
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		Solve(i+1);
	return 0;

}
