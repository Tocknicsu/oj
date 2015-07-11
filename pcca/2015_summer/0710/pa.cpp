#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
    int n;
    while(cin >> n, n){
        vector<ll> v(n);
        ll ans = -1;
        for(int i = 0 ; i < n ; i++){
            cin >> v[i];
            if(i)
                v[i] += v[i-1] > 0 ? v[i-1] : 0;
            ans = max(ans, v[i]);
        }
        if(ans > 0)
            cout << "The maximum winning streak is " << ans << "." << endl;
        else
            cout << "Losing streak." << endl;

    }
    return 0;
}
