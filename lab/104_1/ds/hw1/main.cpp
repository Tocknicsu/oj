#include <cstdio>
#include <cstring>
using namespace std;

char pattern[1048576];
char now[1048576];
int fail[1048576];
int main(){
    freopen("test1.txt", "r", stdin);
    scanf("%s", pattern);
    int pattern_len = strlen(pattern);

    fail[0] = -1;
    int j = -1;
    for(int i = 1 ; i < pattern_len ; i++){
        while(j != -1 && pattern[i] != pattern[j+1]) j = fail[j];
        if(pattern[j+1] == pattern[i]) j++;
        fail[i] = j;
    }
    strcpy(now, pattern);
    int str_num = 0;
    do{
        str_num++;
        j = -1;
        int now_len = strlen(now);
        for(int i = 0 ; i < now_len ; i++){
            while(j != -1 && pattern[j+1] != now[i]) j = fail[j];
            if(pattern[j+1] == now[i]) j++;
            if(j == pattern_len - 1){
                printf("%d", str_num);
                j = fail[j];
            }
        }
    }while(~scanf("%s", now));
    return 0;
}
