#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, m, num[128];
    while(cin >> n >> m){
        num[0] = 1;
        for(int i = 1 ; i <= n ; i++)
            num[i] = 2 * num[i-1];
        for(int i = n + 1 ; i <= m ; i++)
        {
            num[i] = 0;
            for(int j = i - n - 1 ; j < i ; j++)
                num[i] += num[j];
        }
        cout << num[m] << endl;
    }
}

