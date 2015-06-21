#include <iostream>
#include <cstring>
using namespace std;
#define MAX_LEN 131072
char str[MAX_LEN];
int z[MAX_LEN];
void Z_value(char s[], int len){
	int l = 0, r = 0;
	z[0] = len;
	for(int i = 1 ; i < len ; i++){
		int j = max(min(z[i-l], r-i),0);
		for(; i + j < len && s[j] == s[i+j] ; j++);
		z[i] = j;
		if(i+z[i] > r){
			r = i + z[i];
			l = i;
		}
	}
}

int main(){
	scanf("%s", str);
	int len = strlen(str);
	Z_value(str, len);
	for(int i = 0 ; i < len ; i++)
		printf("%d ", z[i]);
}
