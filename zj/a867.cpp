#include <bits/stdc++.h>
using namespace std;
string str[15];
void build(){
    for(int i = 0 ; i < 15 ; i++)
        for(int j = 0 ; j < 30 ; j++){
            if(str[i][j]=='.'){
                str[i][j] = '0';
                for(int x = -1 ; x <= 1 ; x++)
                    for(int y = -1 ; y <= 1 ; y++){
                        int nx = i + x;
                        int ny = j + y;
                        if(nx < 0 || ny < 0 || nx >= 15 || ny >= 30)continue;
                        str[i][j] += str[nx][ny] == '*';
                    }
                if(str[i][j]=='0')
                    str[i][j] = '.';
            }
        }
}
int main(){
    for(int i = 0 ; i < 15 ; i++)
        cin >> str[i];
    build();
    for(int i = 0 ; i < 15 ; i++)
        cout << str[i] << endl;
    return 0;
}
