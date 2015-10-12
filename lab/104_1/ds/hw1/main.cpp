#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;

char pattern[1048576];
char now[1048576];
int fail[1048576];
int ans[1048576];
int main(){
    char in[128], out[128];
    scanf("%s%s", in, out);
    freopen(in, "r", stdin);
    freopen(out, "w", stdout);
    clock_t t = clock();
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
                ans[str_num]++;
                j = fail[j];
            }
        }
    }while(~scanf("%s", now));
    printf("%dms\n", int( (float(clock() - t) / CLOCKS_PER_SEC )*1000));
    for(int i = 1 ; i <= str_num ; i++)
        while(ans[i]--)
            printf("%d", i);
    return 0;
}
