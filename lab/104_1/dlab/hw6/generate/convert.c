#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int a,b,c,d;
    FILE *infile;
    FILE *outfile;
    infile = fopen("input","r");
    if(!infile)
    {
        printf("open file error\n");
        exit(1);
    }
    outfile = fopen("output","w+");
    if(!outfile)
    {
        printf("open file error\n");
        exit(1);
    }
    for(i=0;i<8;i++)
    {
        fscanf(infile,"%d %d %d %d\n",&a,&b,&c,&d);
        fprintf(outfile,"%c%c%c%c",(char)a,(char)b,(char)c,(char)d);
    }
    fclose(outfile);
    fclose(infile);
    return 0;
}
