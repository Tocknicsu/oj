#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string str;
    while(getline(cin, str)){
        stringstream ss(str);
        ll ans = 0, tmp;
        while(ss >> tmp)
            ans += tmp;
        cout << ans << endl;
    }
}
