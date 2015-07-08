#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    string str;
    cin >> str;
    bool ok = false;
    for(int i = 0 ; i < (int)str.size() - 1 ; i++){
        if(!ok){
            if(str[i]=='A' && str[i+1]=='B')
                ok = true, i++;
        } else {
            if(str[i]=='B' && str[i+1]=='A'){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    ok = false;
    for(int i = 0 ; i < (int)str.size() - 1 ; i++){
        if(!ok){
            if(str[i]=='B' && str[i+1]=='A')
                ok = true, i++;
        } else {
            if(str[i]=='A' && str[i+1]=='B'){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
