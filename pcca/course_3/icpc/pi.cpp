#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
int p, len;
char str[1048576];

PII dfs(){
    if(str[p] == '('){
        p++;
        PII a = dfs();
        char op = str[p];
        p++;
        p++;
        PII b= dfs();
        p++;
        if(op == 'U'){
            return PII(max(a.f, b.f), a.s+b.s);
        } else {
            return PII(min(a.f+b.s, a.s+b.f), a.s+b.s);
        }
    } else {
        while(isdigit(str[p]))
            p++;
        p++;
        return PII(1, 1);
    }
}

void Solve(){
    p = 0;
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    len = strlen(str);
    printf("%d\n", dfs().f);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
