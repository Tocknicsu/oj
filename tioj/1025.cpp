#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
vector<PII> v;
int t[9][9];
int row[9][9], col[9][9], sqr[9][9];
int to_sqr(int x, int y){
    return (x / 3) * 3 + y / 3;
}
void print(){
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++)
            printf("%d ", t[i][j]);
        printf("\n");
    }
    printf("\n");
}
int dfs(int p){
    print();
    if( p == (int)v.size() ){
        print();
        return 1;
    }
    int ans = 0;
    for(int i = 0 ; i < 9 ; i++){
        int x = v[p].f;
        int y = v[p].s;
        if(row[x][i] || col[y][i] || sqr[to_sqr(x, y)][i]) continue;
        row[x][i] = col[y][i] = sqr[to_sqr(x, y)][i] = 1;
        t[x][y] = i+1;
        ans += dfs(p+1);
        t[x][y] = 0;
        row[x][i] = col[y][i] = sqr[to_sqr(x, y)][i] = 0;
    }
    return ans;
}
int main(){
    for(int i = 0 ; i < 9 ; i++)
        for(int j = 0 ; j < 9 ; j++){
            int x;
            scanf("%d", &x);
            t[i][j] = x;
            row[i][x-1] = col[j][x-1] = sqr[to_sqr(i, j)][x-1] = 1;
            if(!x)
                v.push_back(PII(i, j));
        }
    printf("there are a total of %d solution(s).\n", dfs(0));
}
