#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void die(){
    cout << "TLE" << endl;
    exit(0);
}
void mpow(ll x, ll y, ll m){
    ll now = 1;
    for(int i = 0 ; i < y ; i++){
        now *= x;
        if(now > m)
            die();
    }
}
int main(){
    ll m, n, t, now = 1;
    cin >> m >> n >> t;
    if(t == 1){
        for(ll i = 1 ; i <= n ; i++){
            now *= i;
            if(now > m)
                die();
        }
    } else if(t == 2){
        mpow(2, n, m);
    } else if(t == 3){
        mpow(n, 4, m);
    } else if(t == 4){
        mpow(n, 3, m);
    } else if(t == 5){
        mpow(n, 2, m);
    } else if(t == 6){
        if(double(n) * double(log2(n)) > m)
            die();
    } else if(t == 7){
        if(n > m)
            die();
    }
    cout << "AC" << endl;
}
