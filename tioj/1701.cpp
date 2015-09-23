#include <bits/stdc++.h>
using namespace std;

int main(){
    char s[256], t[256];
    while(~scanf("%s", s)){
        int sz = strlen(s);
        strcpy(t, s);
        strncat(s+sz, s, sz);
        int x = strstr(s+1, t) - s;
        cout << sz / x << endl;
    }
}
