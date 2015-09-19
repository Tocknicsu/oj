#include <bits/stdc++.h>
using namespace std;
void Solve(int n, int m){
    vector<int> v;
    for(int i = 1 ; i <= n ; i++)
        v.push_back(i);
    int ans = 0;
    do{
        int tmp = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = i ; j < n ; j++){
                int x = 100;
                for(int k = i ; k <= j ; k++)
                    x = min(x, v[k]);
                tmp += x;
            }
        ans = max(ans, tmp);
    }while(next_permutation(v.begin(), v.end()));
    sort(v.begin(), v.end());
    int now = 0;
    do{
        int tmp = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = i ; j < n ; j++){
                int x = 100;
                for(int k = i ; k <= j ; k++)
                    x = min(x, v[k]);
                tmp += x;
            }
        if(tmp == ans){
            now++;
        }
        if(now == m){
            for(int i = 0 ; i < n ; i++)
                cout << v[i] << ' ';
            cout << endl;
            return;
        }
    }while(next_permutation(v.begin(), v.end()));
}
int main(){
    int n, m;
    while(cin >> n >> m)
        Solve(n, m);
}
