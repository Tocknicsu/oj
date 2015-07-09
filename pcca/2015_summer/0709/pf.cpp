#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
        v[i]+=i;
    }
    sort(v.begin(), v.end());
    for(int i = 0 ; i < n ; i++)
        v[i] -= i;
    for(int i = 1 ; i < n ; i++)
        if(v[i] < v[i-1]){
            cout << ":(" << endl;
            return 0;
        }
    for(int i = 0 ; i < n ; i++)
        cout << v[i] << ' ';
    
    return 0;
}
