#include <cstdio>
using namespace std;

bool check(int a, int b, int c, int x, int y){
    return y == a * x * x + b * x + c;
}

void Solve(){
    int x[3], y[3];
    for(int i = 0 ; i < 3 ; i++)
        scanf("%d%d", &x[i], &y[i]);
    for(int i = -64 ; i <= 64 ; i++)
        for(int j = -64 ; j <= 64 ; j++)
            for(int k = -64 ; k <= 64 ; k++){
                bool ok = true;
                for(int l = 0 ; l < 3 ; l++)
                    ok &= check(i, j, k, x[l], y[l]);
                if(ok)
                    printf("%d %d %d\n", i, j, k);
            }

}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
