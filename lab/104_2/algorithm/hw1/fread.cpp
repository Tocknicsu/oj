#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int data[1024];
char out[11];
int k, t;
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
        int output = open("output.txt", O_APPEND);
        //FILE *output = fopen("output.txt", "a+");
        for(int i = 0 ; i < 1024 ; ++i){
            while(data[i]){
                data[i]--;
                if(i==0)
                    write(output, "0", 1);
                    //fputc('0', output);
                k = 0;
                t = i;
                while(t > 0)
                    out[++k] = t % 10, t /= 10;
                while(k)
                    write(output, out, k);
            }
        }
        write(output, "\n", 1);
        close(output);
    }
    close(input);
    return 0;
}
