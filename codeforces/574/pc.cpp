#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, base = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
        base = __gcd(base, v[i]);
    }
    for(int i = 0 ; i < n ; i++){
        if(v[i]%base){
            cout << "No" << endl;
            return 0;
        }
        int x = v[i] / base;
        while(x % 2 == 0)
            x /= 2;
        while(x % 3 == 0)
            x /= 3;
        if(x!=1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
