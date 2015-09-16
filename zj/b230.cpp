#include <bits/stdc++.h>
using namespace std;
#define MAX 2048
bool d[MAX];
int calc(int i, int j, int k){
    return i * j + i * k + j * k;
}
int main(){
    for(int i = 1 ; i < MAX ; i++){
        for(int j = i + 1 ; i * j < MAX ; j++)
            for(int k = j + 1 ; calc(i, j, k) < MAX ; k++){
                d[calc(i, j, k)] = 1;
            }
    }
    vector<int> ans;
    for(int i = 1 ; i < MAX ; i++)
        if(!d[i]){
            ans.push_back(i);
        }
    
    int n;
    while(cin >> n)
        cout << ans[n-1] << endl;
    return 0;
}
