#include <bits/stdc++.h>
using namespace std;
#define INF 1029384756
typedef long long ll;
string get_number(string s, int p){
    int end = p+1;
    for( ; end < (int)s.size() && (isdigit(s[end]) || s[end]=='?') ; end++);
    return s.substr(p, end-p);
}
ll trans(string s, int x){
    if(s.size() > 1 && s[0] == '-' && s[1] == '0') return INF;
    if(s.size() > 1 && s[0] == '-' && s[1] == '?' && x == 0) return INF;
    if(s.size() > 1 && s[0] == '0') return INF;
    if(s[0] == '?' && x == 0 && s.size() != 1 ) return INF;
    for(int i = 0 ; i < (int)s.size() ; i++)
        if(s[i]=='?') s[i] = x + '0';
    stringstream ss(s);
    ll re;
    ss >> re;
    return re;
}
void Solve(){
    string str;
    cin >> str;
    string a = get_number(str, 0);
    string b = get_number(str, a.size()+1);
    string c = get_number(str, a.size()+b.size()+2);
    char op = str[a.size()];
    //cout << a << ' ' << op << ' ' << b << " = " << c << endl;
    for(int i = 0 ; i < 10 ; i++){
        ll x = trans(a, i);
        ll y = trans(b, i);
        ll z = trans(c, i);
        if(x == INF || y == INF || z == INF) continue;
        bool end = false;
        if(op=='+'){
            end = (x + y == z);
        } else if(op=='-'){
            end = (x - y == z);
        } else if(op=='*'){
            end = (x * y == z);
        }
        if(end){
            cout << i;
            return;
        }
    }
    cout << -1;
}
int main(){
//    freopen("pa.in", "r", stdin);
    int n;
    cin >> n;
    while(n--){
        Solve();
        if(n)
            cout << endl;
    }
    return 0;
}
