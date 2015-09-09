#include <bits/stdc++.h>
using namespace std;
bool leap(int x){
    if(!(x%400)) return true;
    if(!(x%100)) return false;
    if(!(x%4)) return true;
    return false;
}
int main(){
    int a, b, ans=0;
    cin >> a >> b;
    for(int i = a ; i <= b ; i++)
        ans += leap(i);
    cout << ans << endl;
}
