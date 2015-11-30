#include <bits/stdc++.h>
using namespace std;
#define MAX 300003
int status[MAX];
char str[MAX];
void print(){
    int n = strlen(str);
    for(int i = 1 ; i <= n ; i++){
        printf("%c", status[i]==0?'(':')');
    }
    printf("\n");
}
struct BIT{
    int v[MAX];
    void init(){
        memset(v, 0, sizeof(v));
    }
    int query(int x){
        int re = 0;
        for( ; x > 0 ; x -= (x & -x )){
            re += v[x];
        }
        return re;
    }
    void add(int x, int m){
        for( ; x < MAX ; x += (x & -x) ){
            v[x] += m;
        }
    }
};

int main(){
    //freopen("pg.in", "r", stdin);
    BIT b[2];
    int n, q, t;
    while(~scanf("%d%d", &n, &q)){
        set<int> s[2];
        b[0].init(), b[1].init();
        scanf("%s", str);
        for(int i = 1 ; i <= n ; i++){
            status[i] = str[i-1] == ')';
            s[status[i]].insert(i);
            b[status[i]].add(i, 1);
        }
        for(int i = 0 ; i < q ; i++){
            scanf("%d", &t);
            int now = status[t];
            if(now){
                int l = b[0].query(t-1);
                int r = b[1].query(t-1);
                int m;
                if(l==r+1){
                    m = t;
                } else {
                    m = *s[0].lower_bound(2);
                }
                b[1].add(t, -1);
                b[0].add(t, 1);
                s[1].erase(t);
                s[0].insert(t);
                b[1].add(m, 1);
                b[0].add(m, -1);
                s[1].insert(m);
                s[0].erase(m);
                printf("%d\n", m);
                status[m] ^= 1;
                status[t] ^= 1;
            } else {
                b[0].add(t, -1);
                b[1].add(t, 1);
                s[0].erase(t);
                s[1].insert(t);
                int m = *s[1].begin();
                b[0].add(m, 1);
                b[1].add(m, -1);
                s[0].insert(m);
                s[1].erase(m);
                printf("%d\n", m);
                status[m] ^= 1;
                status[t] ^= 1;
            }
            print();
        }
    }
    return 0;
}
