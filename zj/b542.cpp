#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void Solve(int t){
    int l = 0, r = 0;
    while(l <= r && r < (int)v.size()){
        if(v[r] - v[l] == t){
            printf("YES\n");
            return;
        }
        if(v[r] - v[l] > t){
            l++;
        } else {
            r++;
        }
    }
    printf("NO\n");
}
int main(){
    int n, m, t;
    scanf("%d%d", &n, &m);
    v = vector<int>(n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for(int i = 0 ; i < m ; i++){
        scanf("%d", &t);
        Solve(t);
    }
    return 0;
}
