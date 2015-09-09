#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[3], ans = 0;
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 3 ; j++)
            cin >> a[j];
        sort(a, a+3);
        if(a[0]+a[1] > a[2]) ans++;
    }
    cout << ans << endl;
}
