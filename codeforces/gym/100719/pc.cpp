#include <bits/stdc++.h>
using namespace std;

void Solve(){
    int n;
    scanf("%d", &n);
    int x[2][128];
    int count[2][131072] = {};
    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < n ; j++){
            scanf("%d", &x[i][j]);
            count[i][x[i][j]]++;
        }
    int ans_max = 0, ans_min = 0;

    sort(x[0], x[0]+n);
    sort(x[1], x[1]+n);

    for(int i = 0 ; i < 131072 ; i++){
        ans_min += max(count[0][i], count[1][i]) * i;
    }
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            ans_max += min(x[0][i], x[1][j]);

    printf("Minimalni budova obsahuje %d kostek, maximalni %d kostek.\n", ans_min, ans_max);
}

int main(){
//freopen("pc.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
