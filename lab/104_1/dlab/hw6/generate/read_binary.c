#include<stdio.h>
#include<stdlib.h>

int main(void)
{
int i;
FILE *infile;
char c1,c2,c3,c4;
infile = fopen("output","r");
if(!infile)
{
	printf("open file error\n");
	exit(1);
}
for(i=0;i<8;i++)
{
	fscanf(infile,"%c%c%c%c",&c1,&c2,&c3,&c4);
	printf("%u %u %u %u\n",(unsigned char)c1,(unsigned char)c2,(unsigned char)c3,(unsigned char)c4);
}
fclose(infile);
return 0;
}
