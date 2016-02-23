#include <bits/stdc++.h>
using namespace std;
struct S{
    int id, value;
    S(){}
    S(int _id, int _value) : id(_id), value(_value){}
    bool operator<(const S &b) const {
        return value == b.value ? id > b.id : value < b.value;
    }
};
int n, s, m;
priority_queue<S> PQ;
bool use[501234];

void add(int x, int y){
    if(x == 0 || x > n || use[x]) return;
    use[x] = 1;
    PQ.push(S(x, abs(x - y) % m));
}

void Solve(){
    memset(use, 0, sizeof(use));
    scanf("%d%d%d", &n, &s, &m);
    PQ.push(S(s, 0));
    use[s] = 1;
    while(PQ.size()){
        printf("%d ", PQ.top().id);
        int u = PQ.top().id;
        PQ.pop();
        add(u/2, u);
        add(u*2, u);
        add(u*2+1, u);
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
