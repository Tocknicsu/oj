#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int main(){
    int n;
    cin >> n;
    vector<PII> x;
    for(int i = 0 ; i < n ; i++){
        int a, b;
        cin >> a >> b;
        x.push_back(PII(a, b));
    }
    x.push_back(PII(0,0));
    sort(x.begin(), x.end());
    int s = lower_bound(x.begin(), x.end(), PII(0, 0)) - x.begin();
    int l = s, r = x.size() - s - 1;
    if(l > r){
        l = r + 1;
    } else if(l < r) {
        r = l + 1;
    }
    int ans = 0;
    for(int i = s - l ; i <= s + r ; i++){
        ans += x[i].second;
    }
    cout << ans << endl;

}
