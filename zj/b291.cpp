#include <bits/stdc++.h>
using namespace std;
map<string, map<string, int> > e;
int main(){
    int n;
    cin >> n;
    while(n--){
        string a, c;
        int b;
        cin >> a >> b >> c;
        e[a][c] += b;
    }
    return 0;
}
