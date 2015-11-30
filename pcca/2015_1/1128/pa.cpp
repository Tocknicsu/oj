#include <bits/stdc++.h>
using namespace std;

struct BIGNUM{
	int value[125], sz;
	int bitvalue[512], bitvaluesz;
	BIGNUM(){}
	BIGNUM(string str){
		for(int i = 0 ; i < (int)str.size() ; i++)
			value[str.size()-1-i] = str[i] - '0';
		sz = str.size();
		bitvaluesz = 0;
	}
	void print(){
		for(int i = sz - 1 ; i >= 0 ; i--){
			printf("%d", value[i]);
		}
		printf("\n");
		for(int i = bitvaluesz - 1 ; i >= 0 ; i--){
			printf("%d", bitvalue[i]);
		}
		printf("\n");
	}
	void trans(){
		for(int k = 0 ; sz ; k++, bitvaluesz++){
			bitvalue[k] = value[0] & 1;
			int new_value[125], re = 0;
			for(int i = sz - 1 ; i >= 0 ; i--){
				re = re * 10 + value[i];
				new_value[i] = re / 2;
				re %= 2;
			}
			if(new_value[sz-1] == 0) sz--;
			for(int i = 0 ; i < sz ; i++){
				value[i] = new_value[i];
			}
		}
	}
	void answer(){
		int ans1 = 0, ans2 = 0, cnt = 0;
		for(int i = 0 ; i < bitvaluesz ; i++){
			if(bitvalue[i]){
				ans1++;
				if(!cnt) ans2++;
				cnt++;
			} else {
				if(cnt > 1){
					ans2++;
					cnt = 1;
				} else {
					cnt = 0;
				}
			}
		}
		if(cnt > 1) ans2++;
		printf("%d %d\n", ans1, ans2);
	}
};

int main(){
	char str[128];
	while(scanf("%s", str), strcmp(str, "0")){
		BIGNUM a(str);
		a.trans();
		a.answer();
	}
	return 0;
}
