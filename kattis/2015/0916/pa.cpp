#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void GG(){
    cout << "TLE" << endl;
    exit(0);
}
int main(){
    ll m, n, t, now = 1;
    cin >> m >> n >> t;
    if(t == 1){
        for(ll i = 1 ; i <= n ; i++){
            now *= i;
            if(now > m)
                GG();
        }
    } else if(t == 2){
        for(ll i = 1 ; i <= n ; i++){
            now *= 2;
            if(now > m)
                GG();
        }
    } else if(t == 3){
        for(ll i = 0 ; i < 4 ; i++){
            now *= n;
            if(now > m)
                GG();
        }
    } else if(t == 4){
        for(ll i = 0 ; i < 3 ; i++){
            now *= n;
            if(now > m)
                GG();
        }
    } else if(t == 5){
        for(ll i = 0 ; i < 2 ; i++){
            now *= n;
            if(now > m)
                GG();
        }
    } else if(t == 6){
        if(double(n) * double(log2(n)) > m)
            GG();
    } else if(t == 7){
        if(n > m)
            GG();
    }
    cout << "AC" << endl;
}
