#include <bits/stdc++.h>
using namespace std;
int t[4][4], d;
void move(){
    for(int k = 0 ; k < 4 ; k++){
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(!t[i][j])
                    swap(t[i][j], t[i][j+1]);
            }
        }
    }
}
void add(){
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(t[i][j] == t[i][j+1]){
                t[i][j] *= 2;
                t[i][j+1] = 0;
            }
        }
    }
}
void trans(int x){
    for(int k = 0 ; k < x ; k++){
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j < i ; j++)
                swap(t[i][j], t[j][i]);
        }
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < 4 ; j++)
                swap(t[i][j], t[3-i][j]);
        }
    }
}

int main(){
    for(int i = 0 ; i < 4 ; i++)
        for(int j = 0 ; j < 4 ; j++)
            cin >> t[i][j];
    cin >> d;
    trans(d);
    move();
    add();
    move();
    trans(4-d);
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++)
            cout << t[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
