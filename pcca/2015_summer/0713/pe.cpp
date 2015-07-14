#include <bits/stdc++.h>
using namespace std;
#define MAX 3009
vector<int> ed[MAX];
int u[MAX];
void DFS(int x, int d){
    if(d==2){
        u[x]++;
        return;
    }
    for(int i = 0 ; i < (int)ed[x].size() ; i++)
        DFS(ed[x][i], d+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        ed[a].push_back(b);
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        fill(u, u+MAX, 0);
        DFS(i, 0);
        for(int j = 1 ; j <= n ; j++)
            if(i!=j && u[j]>=2){
                ans += (u[j] * (u[j]-1))/2;
            }
    }
    cout << ans << endl;
    return 0;
}
