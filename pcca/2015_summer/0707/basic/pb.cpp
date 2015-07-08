#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<string, string> PSS;
vector<PSS> m[128];

int t[5];
int x[10];
int calc(int p){
    int re = 0;
    for(int i = 0 ; i < 5 ; i++)
        re += t[i] * x[p+i];
    return re;
}
string trans(int p){
    char str[6] = {};
    for(int i = 0 ; i < 5 ; i++)
        str[i] = x[4-i+p] + '0';
    return string(str);
}
int main(){
    t[0] = 1;
    for(int i = 1 ; i < 5 ; i++)
        t[i] = t[i-1] * 10;
    for(int i = 0 ; i < 10 ; i++)
        x[i] = i;
    do{
        int a = calc(0), b = calc(5);
        if(a % b == 0 && a / b <= 79){
            m[a/b].push_back(PSS(trans(0), trans(5)));
        }
    } while(next_permutation(x, x+10));
    for(int i = 0 ; i < 128 ; i++)
        sort(m[i].begin(), m[i].end());
    int n;
    bool first = true;
    while(cin >> n, n){
        if(first) first = false;
        else cout << endl;
        if(m[n].empty()){
            cout << "There are no solutions for " << n << "." << endl;
        } else {
            for(int i = 0 ; i < (int)m[n].size() ; i++)
                cout << m[n][i].first << " / " << m[n][i].second << " = " << n << endl;
        }
    }
    return 0;
}
