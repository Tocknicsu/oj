#include <bits/stdc++.h>
using namespace std;
char s[10001024];
char s2[10001024];
int len;
void Xor(){
    for(int i = 0 ; i < len ; i++)
        s[i] = (s[i] != s2[i] ? '1':'0');
}
void add(){
    for(int i = 0 ; i < len ; i++)
        if(s[i] == '1'){
            s[i] = '0';
        } else {
            s[i] = '1';
            break;
        }
}
int main(){
    scanf("%s", s2);
    scanf("%s", s);
    len = strlen(s);
    Xor();
    add();
    Xor();
    printf("%s\n", s);
}
