#include <bits/stdc++.h>
using namespace std;
int t[31], x[131072];
set<int> s;
void process(int sn){
    int n = sn;
    int r = 0;
    while(n != 1){
        if(s.count(n)==1)
            break;
        n >>= 1;
        ++r;
    }
    int k = 0;
    while(n != 1){
        k++;
        n >>= 1;
    }
    for(int i = 0 ; i < 31 ; i++)
        t[i] += r + abs(k-i);
}
int main(){
    int r = 1;
    s.insert(r);
    for(int i = 0 ; i < 30 ; i++){
        r *= 2;
        s.insert(r);
    }
    int n, gcd = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> x[i];
        gcd = __gcd(gcd, x[i]);
    }
    for(int i = 0 ; i < n ; i++){
        x[i] /= gcd;
        process(x[i]);
    }
    int ans = 1029384756;
    for(int i = 0 ; i < 31 ; i++){
        cout << t[i] << endl;
        ans = min(ans, t[i]);
    }
    cout << ans << endl;
}
