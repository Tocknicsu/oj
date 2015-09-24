#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int ans[5022][5022];
void dfs(int remain, int now){
    if(ans[remain][now]) return;
    ans[remain][now] = 1;
    if(remain == 0){
        return;
    }
    for(int i = 0 ; i < (int)v.size() ; i++){
        if(remain >= now + v[i]){
            dfs(remain - now - v[i], now + v[i]);
        }
    }
}
void print(){
    for(int i = 5021 ; i > 0 ; i--)
        if(ans[0][i]){
            printf("%d\n", i);
            return;
        }
    printf("-1\n");
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        memset(ans, 0, sizeof(ans));
        int m, k;
        scanf("%d%d", &m, &k);
        v = vector<int>(k);
        for(int i = 0 ; i < k ; i++)
            scanf("%d", &v[i]);
        dfs(m, 0);
        print();
    }
    return 0;
}
