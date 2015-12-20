#include <bits/stdc++.h>
using namespace std;
int l[10];
int dp[10][10][10];
int Solve(int K){
    for(int i=1;i<=K;i++)
        scanf("%d", &l[i]);
    int N;
    scanf("%d", &N);
    for(int i=K;i>0;i--){
        for(int j=1;j<=l[i];j++){
            if(j==1 && i==K){
                for(int k=1;k<=N;k++)
                    dp[i][j][k] = 1;
            }else if(i==K){
                for(int k=1;k<=N;k++){
                    
                }
            }else if(j==1){
            }else{
            }
        }
    }
}
int main(){
    int K;
    while(~scanf("%d", &K)){
        printf("%d\n", Solve(K));
    }
}
