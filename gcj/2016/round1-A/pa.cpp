#include <bits/stdc++.h>
using namespace std;
char s[1024];

void Solve(int cases){
    list<char> S;
    scanf("%s", s);
    int len = strlen(s);
    S.push_back(s[0]);
    for(int i = 1 ; i < len ; i++){
        if(s[i] >= S.front())
            S.push_front(s[i]);
        else
            S.push_back(s[i]);
    }
    printf("Case #%d: ", cases);
    for(auto x : S)
        printf("%c", x);
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++)
        Solve(i);
    return 0;
}
