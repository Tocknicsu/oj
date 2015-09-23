#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

struct Node{
    Node *l, *r;
    vector<int> v;
    vector<PII> lazy;
    Node(){
    }
    void init(){
        l = r = NULL;
        v.clear();
        lazy.clear();
    }
};
void Solve(){
    int n, m;
    scanf("%d%d", &n, &m);
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
