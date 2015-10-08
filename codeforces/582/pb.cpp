#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    int ans[512];

    scanf("%d%d", &n, &t);
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &v[i]);
    vector<int> l;
    l.push_back(2147483647);
    int nt = min(300, t);
    for(int i = 0 ; i < nt ; i++){
        for(int j = 0 ; j < n ; j++){
            if(v[j]>=l.back()){
                l.push_back(v[j]);
            } else {
                *upper_bound(l.begin(), l.end(), v[j]) = v[j];
            }
        }
        ans[i] = l.size();
    }
    if( t < 300 )
        printf("%d\n", ans[t-1]);
    else
        printf("%d\n", ans[299] + (t-300) * (ans[299]-ans[298]));

    
    return 0;
}
