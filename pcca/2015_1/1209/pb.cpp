#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;

int main(){
    char str[10];
    freopen("pb.in", "r", stdin);
    while(~scanf("%s", str)){
        vector<PII> p;
        int mm_x = 1000, mx_x = 0, mm_y = 1000, mx_y = 0;
        while(scanf("%s", str), str[0] != ']'){
            int x, y;
            sscanf(str, "(%d,%d)", &x, &y);
            p.push_back(PII(x, y));
            mm_x = min(x, mm_x);
            mm_y = min(y, mm_y);
            mx_x = max(x, mx_x);
            mx_y = max(y, mx_y);
        }
        if(mx_x - mm_x <= 3){
            printf("B\n");
            continue;
        }
        if(mx_y - mm_y <= 3){
            printf("A\n");
            continue;
        }
        PII a = p.front(), b = p[p.size()/2], c = p.back();
        printf("%d %d\n", mx_x - mm_x, mx_y - mm_y);
        if(abs((mx_x - mm_x) - (mx_y - mm_y)) <= 1){
            if(a.f >= c.f && a.s >= c.s){
                printf("D\n");
            } else if(a.f <= c.f && a.s <= c.s){
                printf("D\n");
            } else {
                printf("C\n");
            }
        } else {
            printf("E\n");
        }
    }
    return 0;
}
