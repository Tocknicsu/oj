#include <stdio.h>
#include <algorithm>
using namespace std;

int data[20000];

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 0, num, now;
    char c;
    while(c = getchar(), c != '\n')
        n = (n << 3) + (n << 1) + c - 48;
    while(n--){
        num = 0;
        while(1){
            now = 0;
            while(c = getchar(), c != ' ' && c != '\n')
                now = (now << 3) + (now << 1) + c - 48;
            data[num++] = now;
            if(c == '\n')
                break;
        }
        sort(data, data+num);
        for(int i = 0 ; i < num ; ++i)
            printf("%d ", data[i]);
        printf("\n");
    }
    return 0;
}
