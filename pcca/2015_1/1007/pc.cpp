#include <bits/stdc++.h>
using namespace std;
namespace DS{
    int v[32768];
    void init(int n){
        for(int i = 0 ; i < n ; i++)
            v[i] = i;
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    void merge(int x, int y){
        v[find(x)] = find(y);
    }
};

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
