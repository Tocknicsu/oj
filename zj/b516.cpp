#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string str;
    cin >> n;
    while(n--){
        cin >> str;
        for(int i = 0 ; i < (int)str.size() ; i++){
            str[i] = (str[i]-'A'+3)%26+'A';
        }
        cout << str << endl;
    }
    return 0;
}
