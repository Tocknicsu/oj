#include <bits/stdc++.h>
using namespace std;
#define MAX 256
struct S{
    int v, a, b;
    S(){}
    S(int _v, int _a, int _b) : v(_v), a(_a), b(_b) {}
};
bool cmp(const S &a, const S &b){
    return a.v > b.v;
}
void Solve(){
    bool x[MAX] = {}, y[MAX] = {};
    int n;
    scanf("%d", &n);
    vector<S> v;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++){
            int t;
            scanf("%d", &t);
            v.push_back(S(t, i, j));
        }
    sort(v.begin(), v.end(), cmp);
    int ans = 0;
    for(int i = 0 ; i < (int)v.size() ; i++){
        if(x[v[i].a] || y[v[i].b]) continue;
        ans += v[i].v;
        x[v[i].a] = y[v[i].b] = true;
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
}
