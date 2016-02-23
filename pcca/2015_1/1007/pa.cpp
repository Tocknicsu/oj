#include <bits/stdc++.h>
using namespace std;
int Solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &vec[i]);
    sort(vec.begin(), vec.end());
    int ans = 1;
    for(int i = 1 ; i < n ; i++)
        if(vec[i] - vec[i-1] > m)
            ans++;
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++){
        printf("Case #%d: %d\n", i, Solve());
    }
    return 0;
}
