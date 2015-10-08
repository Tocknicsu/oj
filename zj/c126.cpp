#include <bits/stdc++.h>
using namespace std;
string a, b;
void dfs(int ap, int bp, int sz){
    int mid;
    for(int i = 0 ; i < sz ; i++)
        if(b[bp+i] == a[ap]) mid = i;
    int rsz = sz-mid-1;
    if(mid > 0) dfs(ap+1, bp, mid);
    if(rsz > 0) dfs(ap+1+mid, bp+mid+1, rsz);
    cout << a[ap];
}

int main(){
    while(cin >> a >> b){
        dfs(0, 0, a.size());
        cout << endl;
    }
}
