#include <bits/stdc++.h>
using namespace std;

int main(){
    int m = 30001;
    int k = 0;
    for(int i = 1 ; i < m ; i++)
        for(int j = 1 ; j < m ; j++)
            k = i * j;
    printf("%d", k);
    return 0;
}
