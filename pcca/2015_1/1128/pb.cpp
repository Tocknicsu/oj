#include <bits/stdc++.h>
using namespace std;
vector<int> dir[9] = {
    {1, 3},
    {0, 2, 3, 4},
    {1, 4, 5},
    {0, 4, 6},
    {1, 3, 5, 6, 7},
    {2, 4, 7, 8},
    {3, 7},
    {4, 6, 8},
    {5, 7}
};
int board[9];
void decode(int value){
    for(int i = 8 ; i >= 0 ; i--){
        board[i] = value % 10;
        value /= 10;
    }
}
int encode(){
    int re = 0;
    for(int i = 0 ; i < 9 ; i++)
        re = re * 10 + board[i];
    return re;
}
void print(){
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++)
            printf("%d ", board[i*3+j]);
        printf("\n");
    }
    printf("===============\n");
}
void Solve(){
    unordered_map<int, int> M[2];
    queue<int> Q[2];
    for(int j = 0 ; j < 2 ; j++){
        for(int i = 0 ; i < 9 ; i++)
            scanf("%d", &board[i]);
        Q[j].push(encode());
        M[j][Q[j].front()] = 1;
    }
    int flag = 0;
    while(Q[0].size() && Q[1].size()){
        int status = Q[flag].front();
        Q[flag].pop();
        decode(status);
        int zero;
        for(int i = 0 ; i < 9 ; i++)
            if(board[i] == 0) zero = i;
        for(int i = 0 ; i < (int)dir[zero].size() ; i++){
            swap(board[zero], board[dir[zero][i]]);
            int now = encode();
            swap(board[zero], board[dir[zero][i]]);
            if(M[flag^1][now]){
                printf("%d\n", M[flag^1][now] + M[flag][status] - 1);
                return;
            }
            if(M[flag][now]) continue;
            M[flag][now] = M[flag][status] + 1;
            Q[flag].push(now);
        }
        flag ^= 1;
    }
    printf("-1\n");
    return;
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
