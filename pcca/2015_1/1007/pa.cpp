#include <bits/stdc++.h>
using namespace std;
namespace DS{
    int v[128], sz;
    void init(int n){
        for(int i = 0 ; i < n ; i++)
            v[i] = i;
        sz = n;
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    void merge(int x, int y){
        x = find(x), y = find(y);
        if(x != y){
            sz--;
            v[x] = y;
        }
    }
};
int Solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> vec(n);
    DS::init(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &vec[i]);
        for(int j = 0 ; j < i ; j++){
            if(abs(vec[i] - vec[j]) <= m)
                DS::merge(i, j);
        }
    }
    return DS::sz;
}
int Solve2(){
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
//    freopen("pa.in", "r", stdin);
//    Case #1: 3
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++){
        printf("Case #%d: %d\n", i, Solve2());
    }
    return 0;
}
