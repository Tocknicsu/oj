#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x1, y1, x2, y2, ans = 0;
    cin >> n;
    while(n--){
        cin >> x1 >> y1 >> x2 >> y2;
        ans += (abs(x1 - x2)+1) * (abs(y1 - y2)+1);
    }
    cout << ans << endl;
}
