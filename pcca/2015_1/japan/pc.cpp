#include <bits/stdc++.h>
using namespace std;
char str[400000];
int status[400000];
void print(){
    int n = strlen(str);
    for(int j = 1 ; j <= n ; j++){
        printf("%c", status[j] ? ')' : '(');
    }
    printf("\n");
}
int main(){
    freopen("pc.in", "r", stdin);
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        set<int> p[2];
        scanf("%s", str);
        for(int i = 1 ; i < n - 1; i++){
            status[i+1] = str[i] != '(';
            p[status[i+1]].insert(i+1);
        }
        status[1] = 0;
        status[n] = 1;
        int q;
        for(int i = 0 ; i < m ; i++){
            int ans;
            scanf("%d", &q);
            if(q == 1 || q == n){
                ans = q;
            } else {
                ans = *p[status[q]^1].begin();
                if(ans > q){
                    ans = q;
                }
            }
            printf("%d\n", ans);
            p[status[q]].erase(q);
            p[status[ans]].erase(ans);
            p[status[q]].insert(ans);
            p[status[ans]].insert(q);
            status[q] ^= 1;
            status[ans] ^= 1;
            print();

        }
    }
    return 0;
}
