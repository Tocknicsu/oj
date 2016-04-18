#include <bits/stdc++.h>
using namespace std;
int board[3][3];

void print(int t, int k){
    int now = 0;
    for(int i = 0 ; i < 9 ; i++)
        if(board[i/3][i%3])
            now += (1 << (8-i));
    printf("\tb[%d][%d] = %d;\n", t, k, now);
}
void trans(){
    for(int i = 0 ; i < 3 ; i++)
        for(int j = 0 ; j < i ; j++)
            swap(board[i][j], board[j][i]);
    for(int i = 0 ; i < 3 ; i++)
        swap(board[0][i], board[2][i]);
}

int main(){
    freopen("pf_support.in", "r", stdin);
    int t = 0;
    while(~scanf("%1d", &board[0][0])){
        for(int i = 1 ; i < 9 ; i++)
            scanf("%1d", &board[i/3][i%3]);
        for(int i = 0 ; i < 4 ; i++){
            print(t, i);
            trans();
        }
        ++t;
    }
    return 0;
}
