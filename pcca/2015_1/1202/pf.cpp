#include <bits/stdc++.h>
using namespace std;

int month[2][14] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
int source_month[2][14] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
bool is_leap(int y){
    if(y%4) return false;
    if(y%100) return true;
    if(y%400) return false;
    return true;
}
int calc(int y, int m, int d){
    y--;
    int total = y * 365 + y / 4 - y / 100 + y / 400;
    total += month[is_leap(y+1)][m-1] + d;
    return total;
}
void test(){
    int y;
    while(~scanf("%d", &y))
        printf("%d\n", is_leap(y));
}

int main(){
    //freopen("pf.in", "r", stdin);
    for(int i = 1 ; i <= 13 ; i++)
        month[0][i] += month[0][i-1], month[1][i] += month[1][i-1];
    int a, b, c;
    while(~scanf("%4d-%2d-%2d", &a, &b, &c)){
        a--;
        b--;
        int total = 365 * a + a / 4;
        total += month[(a+1)%4==0][b] + c -1;
        int ny = 0, nm = 1, nd = 1;
        while(calc(ny+500, 12, 31) < total){
            ny+=500;
        }
        while(calc(ny+50, 12, 31) < total){
            ny+=50;
        }
        while(calc(ny, 12, 31) < total){
            ny++;
        }
        while(calc(ny, nm, source_month[is_leap(ny)][nm]) < total){
            nm++;
        }
        while(calc(ny, nm, nd) != total)
            nd++;
        printf("%4d-%02d-%02d\n", ny, nm, nd);
    }
    return 0;
}
