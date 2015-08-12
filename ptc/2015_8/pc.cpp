#include <bits/stdc++.h>
using namespace std;

void Solve(){
    int n, tmp;
    scanf("%d", &n);
    vector<int> sat[2];
    vector<int> rdis[20];
    int cut = n / 2 + n & 1;
    for(int k = 0 ; k < 2 ; k++)
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &tmp);
            sat[k].push_back(tmp);
        }
    for(int i = (1 << (n - cut)) - 1 ; i >= 0 ; i--){

    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
