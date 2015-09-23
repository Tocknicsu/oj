#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans = 0, x;
    cin >> x;
    for(int i = 0 ; i < 32 ; i++)
        ans += ((1<<i) & x) != 0;
    cout << ans << endl;
    return 0;
}
