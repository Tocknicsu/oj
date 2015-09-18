#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll squ(ll x){
    return x * x;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int e[6];
    while(cin >> e[0]){
        for(int i = 1 ; i < 6 ; i++)
            cin >> e[i];
        cout << squ(e[0]+e[1]+e[2]) - squ(e[0]) - squ(e[2]) - squ(e[4]) << endl;
    }
}
