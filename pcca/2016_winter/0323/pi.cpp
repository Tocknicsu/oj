#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
    P(){}
    P(int _x, int _y) : x(_x), y(_y){}
    P operator-(const P& b) const {
        return P(x - b.x, y - b.y);
    }
    int operator*(const P &b) const {
        return x * b.x + y * b.y;
    }
};
int Solve(int n){
    vector<P> p(n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d%d", &p[i].x, &p[i].y);
    for(int i = 1 ; i < n ; i++)
        for(int j = i + 1 ; j < n ; j++)
            if((p[i] - p[i-1]) * (p[j] - p[i]) < 0)
                return printf("Unfair\n");
    return printf("Fair\n");
}

int main(){
    int n;
    while(scanf("%d", &n), n)
        Solve(n);
    return 0;
}
