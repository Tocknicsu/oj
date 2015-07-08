#include <iostream>
using namespace std;
int dp[128];
int f(int x){
    if(x <= 100){
        if(dp[x])
            return dp[x];
        return dp[x] = f(f(x+11));
    } else {
        return x - 10;
    }
}
int main(){
    int n;
    while(cin >> n, n)
        cout << "f91(" << n << ") = " << f(n) << endl;
}
