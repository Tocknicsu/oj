#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    char s[16384], b[128];
    while(t--){
        cin >> s >> b;
        int times = 0;
        int len = strlen(s);
        int blen = strlen(b);
        char* p = s;
        while(p){
            p = strstr(p, b);
            if(p){
                p = p+blen;
                times++;
            }
        }
        cout << len - times * (blen - 1)  << endl;
    }
}
