#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
vector<PII> v;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int tmp;
        cin >> tmp;
        v.push_back(PII(tmp, i+1));
    }
    sort(v.begin(), v.end());
    for(int i = 1 ; i <= n ; i++){
        
    }
    return 0;
}
