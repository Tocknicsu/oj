#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &v[i]);
        if(i)
            if(v[i] < v[i-1]){
                printf("no\n");
                return 0;
            }
    }
    printf("yes\n");
    return 0;
}
