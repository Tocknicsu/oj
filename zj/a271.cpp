#include <bits/stdc++.h>
using namespace std;
void Solve(){
    int x, y, z, w, n, m;
    cin >> x >> y >> z >> w >> n >> m;
    string str;
    getline(cin, str);
    getline(cin, str);
    stringstream ss(str);
    int c, d = 0;
    while(ss >> c){
        m -= d;
        if(m < 0){
            cout << "bye~Rabbit" << endl;
            return;
        }
        if(c == 1)
            m += x;
        else if(c == 2)
            m += y;
        else if(c == 3)
            m -= z;
        else if(c == 4){
            m -= w;
            d += n;
        }
        if(m < 0){
            cout << "bye~Rabbit" << endl;
            return;
        }
    }
    cout << m << "g" << endl;
}
int main(){
    int n;
    cin >> n;
    while(n--)
        Solve();
    return 0;
}
