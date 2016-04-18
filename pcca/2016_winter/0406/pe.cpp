#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    int half_n = n / 2;
    int ans = 1029384756;
    for(int i = 0 ; i < half_n ; i++){
        ans = min(ans, v[i] + v[n - i - 1]);
    }
    printf("%d\n", ans);

    return 0;
}
