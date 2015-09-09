#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    ans += n > 5 ? 590 : 0;
    ans += n > 11 ? 200 : 0;
    ans += n > 17 ? 100 : 0;
    ans += n > 59 ? -491 : 0;
    cout << ans << endl;
}
