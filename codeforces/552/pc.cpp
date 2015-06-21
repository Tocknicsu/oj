#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> m >> n;
    while(n > 0){
        int tmp = n % m;
        if(tmp <= 1)
            n /= m;
        else if(tmp == m-1)
            n = n / m + 1;
        else{
            cout << "NO" << endl;
            return false;
        }
    }
    cout << "YES" << endl;
    return 0;
}
