#include <bits/stdc++.h>
using namespace std;
int now[1024];
int n;
bool check(){
    for(int i = 0 ; i < n ; i++)
        if(now[i] != i)
            return false;
    return true;
}
void rotate(){
    for(int i = 0 ; i < n ; i++){
        now[i] += (i&1)?-1:1;
        now[i] = (now[i] + n) % n;
    }
}
int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> now[i];
    for(int i = 0 ; i < n ; i++){
        if(check()){
            cout << "Yes" << endl;
            return 0;
        }
        rotate();
    }
    cout << "No" << endl;
}
