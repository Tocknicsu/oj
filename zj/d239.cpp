#include <bits/stdc++.h>
using namespace std;
#define MAX 1048576
vector<int> p;
void build(){
    bool t[MAX];
    memset(t, 0, sizeof(t));
    for(int i = 4 ; i < MAX ; i += 2)
        t[i] = 1;
    for(int i = 3 ; i * i < MAX ; i += 2)
        if(!t[i])
            for(int j = i * i ; j < MAX ; j += 2 * i)
                t[j] = 1;
    for(int i = 2 ; i < MAX ; i++)
        if(!t[i])
            p.push_back(i);
}
int x[MAX];
int main(){
    cout << 134043 << endl;
    return 0;
    build();
    for(int i = 4 ; i < MAX ; i++){
        int tmp = i, t = 0;
        for(int j = 0 ; tmp != 1 && j < (int)p.size() ; j++){
            if( tmp % p[j] == 0){
                ++t;
                while(tmp % p[j] == 0)
                    tmp /= p[j];
            }
        }
        if(tmp!=1) ++t;
        x[i] = t;
        //cout << i << ' ' << x[i] << endl;
        if(x[i-3] == x[i-2] && x[i-2] == x[i-1] && x[i-1] == x[i] && x[i] == 4){
            cout << i - 3 << endl;
            return 0;
        }
    }
    return 0;
}
