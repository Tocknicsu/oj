#include <bits/stdc++.h>
using namespace std;
char c[12][12];
int d[12][12];
int go(int x){
    memset(d, 0, sizeof(d));
    for(int i = 0 ; i < 10 ; i++)
        d[0][i] = ((1 << i) & x) != 0;
    for(int i = 1 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            d[i][j] = c[i-1][j] == 'O';
            if(d[i-1][j])
                d[i][j] ^= 1;
            if(j && d[i-1][j-1])
                d[i][j] ^= 1;
            if(j + 1 < 10  && d[i-1][j+1])
                d[i][j] ^= 1;
            if(i - 1 > 0 && d[i-2][j])
                d[i][j] ^= 1;
        }
    }
    for(int i = 0 ; i < 10 ; i++){
        int j = c[9][i] == 'O';
        if(i && d[9][i-1]) j ^= 1;
        if(i + 1 < 10 && d[9][i+1])  j ^= 1;
        if(d[8][i]) j ^= 1;
        if(d[9][i]) j ^= 1;
        if(j){
            return 1029384756;
        }
    }
    int times = 0;
    for(int i = 0 ; i < 10 ; i++)
        for(int j = 0 ; j < 10 ; j++)
            times += d[i][j];
    return times;
}
int Solve(){
    int ans = 1029384756;
    for(int i = 0 ; i < 10 ; i++)
        cin >> c[i];
    for(int i = 0 ; i < 1024 ; i++){
        ans = min(ans, go(i));
    }
    return ans <= 1000 ? ans : -1;
}
int main(){
    string name;
    while(cin >> name, name != "end"){
        cout << name << ' ' << Solve() << endl;
    }
}
