#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    int x = 0, y = 0;
    for(int i = 0 ; i < (int)str.size() ; i++){
        if(str[i] == 'A' && str[i+1] == 'B' && x == 0)
            x++, i++;
        else if(str[i] == 'B' && str[i+1] == 'A' && x == 1){
            cout << "YES" << endl;
            return 0;
        }
    }
    for(int i = 0 ; i < (int)str.size() ; i++){
        if(str[i] == 'B' && str[i+1] == 'A' && y == 0)
            y++, i++;
        else if(str[i] == 'A' && str[i+1] == 'B' && y == 1){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
