#include <bits/stdc++.h>
using namespace std;
#define MAX 671065
bool isprime[MAX];
void build(){
    isprime[0] = isprime[1] = 1;
    for(int i = 4 ; i < MAX ; i += 2)
        isprime[i] = 1;
    for(int i = 3 ; i * i < MAX ; i += 2)
        if(!isprime[i])
            for(int j = i * i ; j < MAX ; j += 2 * i)
                isprime[j] = 1;
}
int main(){
    build();
    int t;
    ios_base::sync_with_stdio(0), cin.tie(0);
    while(cin >> t)
        cout << (isprime[t] ? "It's not a prime!!!" : "It's a prime!!!") << endl;
    return 0;
}
