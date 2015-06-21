#include <bits/stdc++.h>
using namespace std;
string str;
bool exist[1000];
int main(){
    cin >> str;
    for(int i = 0 ; i < (int)str.size() ; i++){
        int x = str[i] - '0';
        if(!(x % 8)){
            cout << "YES" << endl;
            cout << x << endl;
            return 0;
        }
        for(int j = 99 ; j >= 0 ; j--){
            if(exist[j]){
                exist[j * 10 + x] = true;
                if(!((j*10 + x)%8)){
                    cout << "YES" << endl;
                    cout << j*10+x << endl;
                    return 0;
                }
            }
            
        }
        exist[x] = 1;
    }
    cout << "NO" << endl;
}
