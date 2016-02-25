#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    scanf("%d", &x);
    int row[128], col[128];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    char str[128];
    for(int i = 0 ; i < x ; i++){
        scanf("%s", str);
        for(int j = 0 ; j < x ; j++)
            if(str[j] == 'C'){
                row[i]++;
                col[j]++;
            }
    }
    int ans = 0;
    for(int i = 0 ; i < x ; i++){
        ans += (row[i] * (row[i]-1) / 2);
        ans += (col[i] * (col[i]-1) / 2);
    }
    printf("%d\n", ans);
    
    return 0;
}
