#include <bits/stdc++.h>
using namespace std;
#define MOD 10007

int main(){
    int a, b, c;
    int t;
    cin >> t;
    while(t--){
        scanf("%d%d%d", &a, &b, &c);
        a = (a % MOD) * (c % MOD) % MOD;
        b = (b % MOD) * (c % MOD) % MOD;
        cout << (a==b?"SAFE":"BOOM") << endl;
    }
    return 0;
}
