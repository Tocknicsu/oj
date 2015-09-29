#include <bits/stdc++.h>
using namespace std;
#define MAX 32768
char A[MAX], B[MAX], C[MAX];
void Solve(){
    int n, a, b, c;
    int ab, ac, bc, re;
    a = b = c = 0;
    ab = ac = bc = 0, re = 0;
    scanf("%d", &n);
    scanf("%s%s%s", A, B, C);
    for(int i = 0 ; i < n ; i++){
        if(A[i] == B[i] && B[i] == C[i]){
            a++, b++, c++;
        } else if(A[i] == B[i]){
            a++, b++, ab++;
        } else if(A[i] == C[i]){
            a++, c++, ac++;
        } else if(B[i] == C[i]){
            b++, c++, bc++;
        } else {
            re++;
        }
    }
    while(re){
        if(a <= b && a <= c && re)
            a++, re--;
        if(b <= a && b <= c && re)
            b++, re--;
        if(c <= a && c <= b && re)
            c++, re--;
    }
    while(a < b && a < c && bc){
        a++, b--, c--, bc--;
    }
    while(b < c && b < a && ac){
        b++, a--, c--, ac--;
    }
    while(c < a && c < b && ab){
        c++, a--, b--, ab--;
    }
    cout << min(a, min(b, c)) << endl;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
}
