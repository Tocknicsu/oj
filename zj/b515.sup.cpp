#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    for(int i = 0 ; i < 26 ; i++){
        cin >> a >> b;
        printf("m[\"%s\"]='%s';\n", b.c_str(), a.c_str());
    }
}
