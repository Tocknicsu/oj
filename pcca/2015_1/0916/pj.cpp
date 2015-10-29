#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
struct S{
    ll s[2];
    S(){}
    S(int a, int b){
        s[0] = a;
        s[1] = b;
    }
    S& operator=(const S& b){
        for(int i = 0 ; i < 3 ; i++)
            s[i] = b.s[i];
        return (*this);
    }
    S operator+(const S& b) const {
        S re;
        re.s[0] = s[0] + b.s[0];
        re.s[1] = (s[1] * b.s[1]) % 1000000007;
        return re;
    }
};
int _hash(int x){
    return (x + 10007) % 100019;
}
set<PII> s;
string str[2];
int ans;
int p;
S build(int t){
    S re;
    if(str[t][p] == '('){
        ++p;
        S x = build(t);
        ++p;
        S y = build(t);
        re = x + y;
        ++p;
    }
    if(isdigit(str[t][p])){
        int x = 0;
        while(isdigit(str[t][p])){
            x = x * 10 + str[t][p++] - '0';
        }
        x = _hash(x);
        re = S(x, x);
    }
    if(!t){
        s.insert(PII(re.s[0], re.s[1]));
    } else {
        ans += s.count(PII(re.s[0], re.s[1]));
    }
    return re;
}
int main(){
    int n;
    cin >> n;
    cin >> str[0] >> str[1];
    build(0);
    p = 0;
    build(1);
    cout << ans << endl;
}
