#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    vector<ll> v;
    v.push_back(3);
    for(; v.back() * 2 < 1000000000ll ; v.push_back(v.back()*2));
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int flag = 0;
        for(int i = (int)v.size()- 1 ; i >= 0 ; i--){
            if(n > v[i]){
                flag ^= 1;
                n-=v[i];
            }
        }
        cout << (flag ? 4 - n : n) << endl;
    }
    
}
