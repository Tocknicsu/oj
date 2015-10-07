#include <bits/stdc++.h>
using namespace std;
namespace DS{
    int v[32768];
    void init(){
        for(int i = 0 ; i < 32768 ; i++)
            v[i] = i;
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    void merge(int x, int y){
        if(x == 0 || y == 0){
            return;
        }
        v[find(x)] = find(y);
    }
};
struct Q{
    int t;
    int x, y;
    Q(){}
    Q(int _t, int _x, int _y) : t(_t), x(_x), y(_y) {}
};
void Solve(){
    int n, q;
    scanf("%d%d", &n, &q);
    DS::init();
    int v[32768];
    for(int i = 1 ; i <= n ; i++)
        scanf("%d", &v[i]);
    vector<Q> query;
    int ok[32768];
    fill(ok, ok+32768, 0);
    char s[2];
    int x, y;
    for(int i = 0 ; i < q ; i++){
        scanf("%s", s);
        if(s[0] == 'Q'){
            scanf("%d%d", &x, &y);
            query.push_back(Q(1, x, y));
        } else {
            scanf("%d", &x);
            ok[x]++;
            query.push_back(Q(0, x, 0));
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(!ok[i])
            DS::merge(i, v[i]);
    }
    stack<int> ans;
    for(int i = (int)query.size() - 1; i >= 0 ; i--)
        if(query[i].t){
            ans.push(DS::find(query[i].x) == DS::find(query[i].y));
        } else {
            ok[query[i].x]--;
            if(!ok[query[i].x])
                DS::merge(query[i].x, v[query[i].x]);
        }
    while(ans.size()){
        printf("%s\n", ans.top()?"YES":"NO");
        ans.pop();
    }
}

int main(){
    //freopen("pc.in", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int i = 1 ; i <= t ; i++){
        printf("Case #%d:\n", i);
        Solve();
    }
    return 0;
}
