#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m[100];
int w[100];
int main(){
    int x;
    cin >> x;
    while(x--){
        ll t, c;
        cin >> t >> c;
        c++;
        if( t % 1000 != 0){
            puts("0");
            continue;
        }
        t /= 1000;
        ll a = 0, b = 1, x = 1;
        while(t){
            int r = t % 10;
            if(c){
                c--;
                a += m[r];
                b *= w[r];
            } else {
                x *= 10;
                a += m[r] * x / 5;
            }
            t /= 10;
        }
        cout << a << ' ' << b << endl;
    }
    return 0;
}
/*
 * 9 8 7 6 5 4 3 2 1 0
 * 1
 * 9,8 9+8
 * 98,7 9,87
 * /
