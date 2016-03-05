#include <bits/stdc++.h>
using namespace std;
#define MAX 5002
#define f first
#define s second
typedef pair<int, int> PII;
PII row[MAX], col[MAX];

int main(){
//    freopen("pb.in", "r", stdin);
    int x, y, n;
    scanf("%d%d%d", &x, &y, &n);
    for(int i = 1 ; i <= n ; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a == 1){
            row[b] = PII(i, c);
        } else {
            col[b] = PII(i, c);
        }
    }
    for(int i = 1 ; i <= x ; i++){
        for(int j = 1 ; j <= y ; j++){
            printf("%d ", row[i].f > col[j].f ? row[i].s : col[j].s);
        }
        printf("\n");
    }
    
    return 0;
}
