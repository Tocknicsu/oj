#include <bits/stdc++.h>
using namespace std;
#define l first
#define r second
#define MAX 32768
typedef pair<int, int> PII;
PII child[2][MAX];
char node[2][MAX][10];

bool dfs(int a, int b){
    if(strcmp(node[0][a], node[1][b])) return false;
    if(child[0][a] == PII(0, 0) && child[1][b] == PII(0, 0)) return true;
    if(child[0][a] == PII(0, 0) || child[1][b] == PII(0, 0)) return false;
    return 
        (dfs(child[0][a].l, child[1][b].l) && dfs(child[0][a].r, child[1][b].r)) ||
        (dfs(child[0][a].l, child[1][b].r) && dfs(child[0][a].r, child[1][b].l));
}

void Solve(){
    int n;
    scanf("%d", &n);
    for(int k = 0 ; k < 2 ; k++)
        for(int i = 1 ; i <= n ; i++){
            scanf("%s%d%d", node[k][i], &child[k][i].l, &child[k][i].r);
        }
    printf("%s\n", dfs(1, 1)?"yes":"no");
}

int main(){
    //freopen("pd.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
