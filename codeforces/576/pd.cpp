#include <bits/stdc++.h>
using namespace std;
int adj[152][152];
int n, m;
bool ok(int guess){
    Matrix tmp;
    return tmp[1][n] 
}
int main(){
    memset(adj, -1, sizeof(adj));
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }
    int ans = 0, step = 1029384756;
    while(step){
        if(!ok(ans+step)){
            ans+=step;
        } else {
            step >>= 1;
        }
    }
    return 0;
}
