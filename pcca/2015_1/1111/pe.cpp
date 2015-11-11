#include <bits/stdc++.h>
using namespace std;
string m, n;
struct S{
    string s[3];
    S(){}
    S(string _s){
        int flag = 0;
        for(int i = 0 ; i < (int)_s.size() ; i++){
            if(_s[i] == '(' || _s[i] == '.') flag++;
            else if(_s[i] == ')') continue;
            else s[flag].push_back(_s[i]-'0');
        }
    }
    void print(){
        for(int i = 0 ; i < (int)s[0].size() ; i++)
            cout << char(s[0][i]+'0');
        cout << '.';
        for(int i = 0 ; i < (int)s[1].size() ; i++)
            cout << char(s[1][i]+'0');
        cout << '(';
        for(int i = 0 ; i < (int)s[2].size() ; i++)
            cout << char(s[2][i]+'0');
        cout << ')' << endl;
    }
    void merge(S& _s){
        while( (int)s[1].size() < (int)_s.s[1].size() ){
            s[1].push_back(s[2][0]);
            s[2].push_back(s[2][0]);
            s[2] = s[2].substr(1, s[2].size()-1);
        }
        while( (int)s[1].size() > (int)_s.s[1].size() ){
            _s.s[1].push_back(_s.s[2][0]);
            _s.s[2].push_back(_s.s[2][0]);
            _s.s[2] = _s.s[2].substr(1, _s.s[2].size()-1);
        }
        int _m = s[2].size();
        int _n = _s.s[2].size();
        int x = _m / __gcd(_m, _n) * _n;
        string __m = s[2], __n = _s.s[2];
        for(int i = 0 ; i < (x / _m) - 1 ; i++){
            s[2] += __m;
        }
        for(int j = 0 ; j < (x / _n) - 1 ; j++){
            _s.s[2] += __n;
        }
        for(int i = 0 ; i < (int)s[1].size() ; i++){
            s[1][i] = s[1][i] + _s.s[1][i];
        }
        for(int i = 0 ; i < (int)s[2].size() ; i++){
            s[2][i] = s[2][i] + _s.s[2][i];
        }
        for(int i = (int)s[2].size() ; i > 0 ; i--){
            if(s[2][i] >= 10){
                s[2][i] -= 10;
                s[2][i-1]++;
            }
        }
        if(s[2][0] >= 10){
            s[2][0] -= 10;
            s[1][(int)s[0].size()-1]++;
        }
        for(int i = (int)s[1].size() ; i > 0 ; i--){
            if(s[1][i] >= 10){
                s[1][i] -= 10;
                s[1][i-1]++;
            }
        }
        if(s[1][0] >= 10){
            s[1][0] -= 10;
            s[0][0]++;
        }
        while(s[1].size() && s[1][s[1].size()-1] == s[2][s[2].size()-1]){
            s[1].pop_back();
            s[2].push_back(s[2][0]);
            s[2] = s[2].substr(1, s[2].size()-1);
        }
        char another[200], one[200];
        strcpy(one, s[2].c_str());
        strcpy(another, one);
        strcat(another, one);
        char *p = strstr(another+1, one);
        int q = p - another;
        s[2] = s[2].substr(0, q);
    }
};
int main(){
    freopen("pa.in", "r", stdin);
    ios_base::sync_with_stdio(0), cin.tie(0);
    while(cin >> m >> n){
        S M(m), N(n);
        M.merge(N);
        M.print();
    }
    return 0;
}
