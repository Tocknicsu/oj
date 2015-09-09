#include<bits/stdc++.h>
using namespace std;
/* 
python3
x = 0
for i in range(1, 1001):
    x += i ** i
print(x)
*/
typedef long long ll;
const ll base = 10000000ll;
const int base_pos = 7;
struct BIGNUM{
    vector<ll> v;
    BIGNUM(){}
    BIGNUM(int n){
        while(n){
            v.push_back(n%base);
            n /= base;
        }
    }
    void print(){
        cout << v[v.size()-1];
        for(int i = (int)v.size() - 2 ; i >= 0 ; i--){
            cout << setw(7) << setfill('0') << v[i];
        }
    }
    BIGNUM operator+(const BIGNUM& b) const {
        BIGNUM re;
        int to = max(v.size(), b.v.size());
        for(int i = 0 ; i < to ; i++){
            int tmp = 0;
            if(i < (int)v.size()) tmp += v[i];
            if(i < (int)b.v.size()) tmp += b.v[i];
            re.v.push_back(tmp);
        }
        re.format();
        return re;
    }
    BIGNUM operator*(const BIGNUM& b) const {
        BIGNUM re;
        re.v = vector<ll>((int)v.size() + (int)b.v.size()-1);
        for(int i = 0 ; i < (int)v.size() ; i++)
            for(int j = 0 ; j < (int)b.v.size() ; j++)
                re.v[i+j] += v[i] * b.v[j];
        re.format();
        return re;
    }
    BIGNUM& operator*=(const BIGNUM& b){
        return (*this) = (*this) * b;
    }
    BIGNUM operator^(int b) const {
        BIGNUM re(1), tmp=(*this);
        while(b){
            if(b&1){
                re *= tmp;
            }
            tmp *= tmp;
            b >>= 1;
        }
        return re;
    }
    void format(){
        for(int i = 0 ; i < (int)v.size() ; i++){
            if(v[i] / base){
                if(i == (int)v.size()-1){
                    v.push_back(v[i]/base);
                } else {
                    v[i+1] += v[i] / base;
                }
                v[i] %= base;
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    BIGNUM ans(0);

    for(int i = 1 ; i <= 1000 ; i++){
        ans = ans + (BIGNUM(i)^i);
    }
    ans.print();
}
