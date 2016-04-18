#include <bits/stdc++.h>
using namespace std;
#define MAX 512
int d[MAX][MAX];
int p[MAX];
struct S{
    int s, f, t;
    S(){}
    S(int _s, int _f, int _t) : s(_s), f(_f), t(_t) {}
};

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<S> s(m);
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &p[i]);
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            scanf("%d", &d[i][j]);
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                d[i][j] = min(d[i][j], d[i][k] + p[k] + d[k][j] + p[j]);
    for(int i = 0 ; i < m ; i++){

    }
    return 0;
}
