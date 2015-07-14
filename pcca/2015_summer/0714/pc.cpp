#include <bits/stdc++.h>
using namespace std;
namespace DS{
    const int MAX = 32768;
    int v[MAX];
    void init(int n){
        for(int i = 0 ; i < n ; i++)
            v[i] = i;
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    void merge(int x, int y){
        x = find(x), y = find(y);
        v[x] = y;
    }
};
int main(){
    int n;
    cin >> n;
    DS::init(2*n);
    int a, b, c;
    while(cin >> a >> b >> c, a || b || c){
        if(a == 1){
            if(DS::find(b) == DS::find(c+n) || DS::find(c) == DS::find(b+n)){
                cout << "-1" << endl;
                continue;
            }
            DS::merge(b, c);
            DS::merge(b+n, c+n);
        } else if(a == 2){
            if(DS::find(b) == DS::find(c) || DS::find(b+n) == DS::find(c+n)){
                cout << "-1" << endl;
                continue;
            }
            DS::merge(b, c+n);
            DS::merge(b+n, c);
        } else if(a == 3){
            cout << (DS::find(b) == DS::find(c)) << endl;
        } else if(a == 4){
            cout << (DS::find(b+n) == DS::find(c)) << endl;
        }
    }
    return 0;
}
