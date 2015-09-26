#include <bits/stdc++.h>
using namespace std;

map<string, char> m;
int main(){
    m[".-"]='A';
    m["-..."]='B';
    m["-.-."]='C';
    m["-.."]='D';
    m["."]='E';
    m["..-."]='F';
    m["--."]='G';
    m["...."]='H';
    m[".."]='I';
    m[".---"]='J';
    m["-.-"]='K';
    m[".-.."]='L';
    m["--"]='M';
    m["-."]='N';
    m["---"]='O';
    m[".--."]='P';
    m["--.-"]='Q';
    m[".-."]='R';
    m["..."]='S';
    m["-"]='T';
    m["..-"]='U';
    m["...-"]='V';
    m[".--"]='W';
    m["-..-"]='X';

    m["-.--"]='Y';
    m["--.."]='Z';

    int n;
    cin >> n;
    string str;
    getline(cin, str);
    while(n--){
        getline(cin, str);
        stringstream ss(str);
        string s;
        while(ss >> s){
            cout << m[s];
        }
        cout << endl;
    }
    return 0;
}
