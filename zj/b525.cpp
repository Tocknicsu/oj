#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 100000007
struct Matrix{
    ll v[2][2];
    Matrix(){
        memset(v, 0, sizeof(v));
    }
    void I(){
        for(int i = 0 ; i < 2 ; i++)
            v[i][i] = 1;
    }
    Matrix operator*(const Matrix &b) const {
        Matrix re;
        for(int i = 0 ; i < 2 ; i++)
            for(int j = 0 ; j < 2 ; j++)
                for(int k = 0 ; k < 2 ; k++){
                    re.v[i][j] += v[i][k] * b.v[k][j];
                    re.v[i][j] %= MOD;
                }
        return re;
    }
    Matrix operator^(int b) const {
        Matrix re, tmp = (*this);
        re.I();
        while(b){
            if(b&1){
                re = re * tmp;
            }
            tmp = tmp * tmp;
            b >>= 1;
        }
        return re;
    }
    void print(){
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < 2 ; j++)
                cout << v[i][j] << ' ';
            cout << endl;
        }
    }
};
int main(){
    ll a, b, c;
    Matrix t;
    t.v[0][0] = 0;
    t.v[0][1] = 1;
    t.v[1][0] = 1;
    t.v[1][1] = 1;
    while(cin >> a >> b >> c){
        Matrix tmp = t ^ c;
        ll ans = a * (tmp.v[0][0] + tmp.v[1][0]) + b * (tmp.v[0][1] + tmp.v[1][1]);
        ans %= MOD;
        cout << ans << endl;

    }
    return 0;
}
