#include <bits/stdc++.h>
using namespace std;

void Solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> p(m);
    for(int i = 0 ; i < m ; i++)
        scanf("%d", &p[i]);
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
