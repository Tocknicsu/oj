#include <bits/stdc++.h>
using namespace std;
char str[1048576];
int main(){
    vector<int> v;
    while(~scanf("%s", str)){
        v.clear();
        for(int i = strlen(str) - 1 ; i >= 0 ; i--)
            v.push_back(str[i] - '0');
        for(int i = 0 ; i < (int)v.size() ; i++){
            v[i] ^= 1;
            if(i&1){
                if(v[i] == 0)
                    break;
                else{
                    if(i == (int)v.size() - 1)
                        v.push_back(0);
                }
                
            } else {
                if(v[i] == 1){
                    break;
                } else {
                    if(i == (int)v.size() - 1)
                        v.push_back(0);
                }
            }
        }
        while(v.back() == 0 && v.size() > 1) v.pop_back();
        for(int i = (int)v.size() - 1 ; i >= 0 ; i--)
            printf("%d", v[i]);
        printf("\n");
    }
    return 0;
}
