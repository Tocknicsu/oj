#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int data[1024];
int out[11], k, t;
int main(){
    int input = open("input.txt", O_RDONLY);
    int n = 0, now;
    char c;
    while(read(input, &c, 1), c != '\n')
        n = n * 10 + c - 48;
    if(n > 5)
        return 0;
    while(n--){
        while(1){
            now = 0;
            while(read(input, &c, 1), c != ' ' && c != '\n')
                now = now * 10 + c - 48;
            data[now]++;
            if(c == '\n')
                break;
        }
        for(int i = 0 ; i < 1024 ; ++i){
            while(data[i]){
                data[i]--;
                if(i==0){
                    FILE *output = fopen("output.txt", "a+");
                    fputc('0', output);
                    fclose(output);
                }
                k = 0;
                t = i;
                while(t > 0)
                    out[++k] = t % 10, t /= 10;
                FILE *output = fopen("output.txt", "a+");
                while(k){
                    fputc(out[k--]+48, output);
                }
                fputc(32, output);
                fclose(output);
            }
        }
        FILE *output = fopen("output.txt", "a+");
        fputc('\n', output);
        fclose(output);
    }
    close(input);
    return 0;
}
