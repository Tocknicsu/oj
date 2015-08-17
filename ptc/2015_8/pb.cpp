#include <bits/stdc++.h>
using namespace std;
struct S{
    int a, b, c;
    S(){}
    S(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};
bool cmp(const S &a, const S &b){
    return a.c > b.c;
}
namespace DS{
    int v[1024], sz;
    void init(int n){
        for(int i = 0 ; i < n ; i++)
            v[i] = i;
        sz = n;
    }
    int size(){
        return sz;
    }
    int find(int x){
        return v[x] == x ? v[x] : v[x] = find(v[x]);
    }
    void merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        v[x] = y;
        sz--;
    }
};
void Solve(){
    int k, n, m;
    vector<S> v;
    scanf("%d %d %d", &k, &n, &m);
    for(int i = 0 ; i < m ; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v.push_back(S(a, b, c));
    }
    sort(v.begin(), v.end(), cmp);
    DS::init(n);
    for(int i = 0 ; i < (int)v.size() ; i++){
        if(DS::size() == k){
            if(DS::find(v[i].a) != DS::find(v[i].b)){
                printf("%d\n", v[i].c);
                return;
            }
        } else {
            DS::merge(v[i].a, v[i].b);
        }
    }
    printf("0\n");
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
}
