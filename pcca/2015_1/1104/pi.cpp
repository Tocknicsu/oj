#include <bits/stdc++.h>
using namespace std;
map<char, int> number;
map<char, int> flower;

void Solve(){
    char s[3];
    int card[52] = {0};
    for(int i = 0 ; i < 26 ; i++){
        scanf("%s", s);
        card[(number[s[0]]-1) * 4 + flower[s[1]]-1] = 1;
    }
    vector<int> c[2];
    int ans = 0;
    for(int i = 51 ; i >= 0 ; i--)
        c[card[i]].push_back(i);
    /*
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 26 ; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    */
    int i = 0, j = 0;
    while(i < 26 && j < 26){
        while(i < 26 && c[0][i] > c[1][j]) i++;
        if(i == 26) continue;
        ans++;
        j++;
        i++;
    }
    printf("%d\n", ans);
}

int main(){
    //freopen("pi.in", "r", stdin);
    number['2'] = 1;
    number['3'] = 2;
    number['4'] = 3;
    number['5'] = 4;
    number['6'] = 5;
    number['7'] = 6;
    number['8'] = 7;
    number['9'] = 8;
    number['T'] = 9;
    number['J'] = 10;
    number['Q'] = 11;
    number['K'] = 12;
    number['A'] = 13;
    flower['D'] = 1;
    flower['C'] = 2;
    flower['H'] = 3;
    flower['S'] = 4;
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
