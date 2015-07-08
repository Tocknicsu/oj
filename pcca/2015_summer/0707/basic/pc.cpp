#include <iostream>
using namespace std;

void Solve(){
    int x[20][20] = {};
    for(int i = 1 ; i < 20 ; i++)
        for(int j = 1 ; j < 20 ; j++)
            cin >> x[i][j];
    for(int i = 1 ; i < 20 ; i++)
        for(int j = 1 ; j < 20 ; j++){
            bool end = false;
            if(x[i][j]){
                if(i<=15){
                    bool tmp = true;
                    for(int k = 0 ; k < 5 ; k++)
                        if(x[i][j] != x[i+k][j])
                            tmp = false;
                    end |= tmp;
                }
                if(j<=15){
                    bool tmp = true;
                    for(int k = 0 ; k < 5 ; k++)
                        if(x[i][j] != x[i][j+k])
                            tmp = false;
                    end |= tmp;
                }
                if(i<=15 && j <=15){
                    bool tmp = true;
                    for(int k = 0 ; k < 5 ; k++)
                        if(x[i][j] != x[i+k][j+k])
                            tmp = false;
                    end |= tmp;
                }
                if(i>=4 && j <=15){
                    bool tmp = true;
                    for(int k = 0 ; k < 5 ; k++)
                        if(x[i][j] != x[i-k][j+k])
                            tmp = false;
                    end |= tmp;
                }
            }
            if(end){
                cout << x[i][j] << endl;
                cout << i << ' ' << j << endl;
                return;
            }
        }
    cout << 0 << endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while(n--)
        Solve();
    return 0;
}
