#include <bits/stdc++.h>
using namespace std;
bool get_bit(int n, int p){
    return n & ( 1 << p );
}
int main(){
    int a, b, c;
    while(cin >> a >> b >> c){
        if(get_bit(a, b) ^ c)
            a ^= (1 << b);
        for(int i = 31 ; i >= 0 ; i--)
            cout << get_bit(a, i);
        cout << endl;
    }
}
