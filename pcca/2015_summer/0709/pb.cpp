#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    int ans = max(vec[0], m-vec[vec.size()-1]) * 2;
    for(int i = 1 ; i < n ; i++)
        ans = max(ans, (vec[i] - vec[i-1]));
    cout << (ans / 2) << (ans&1?".5000000000":".0000000000") << endl;
    return 0;
}
