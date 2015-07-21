#include <bits/stdc++.h>
using namespace std;
int times[1048576], l[1048576], r[1048576];
int max_times = 0;
int main(){
    int n, x;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> x;
        if(times[x] == 0){
            l[x] = i;
            r[x] = i;
        } else {
            r[x] = i;
        }
        times[x]++;
        max_times = max(max_times, times[x]);
    }
    int min_range = 1029348576, min_l, min_r;
    for(int i = 0 ; i < 1048576 ; i++){
        if(times[i] == max_times){
            if(r[i] - l[i] < min_range){
                min_range = r[i] - l[i];
                min_l = l[i], min_r = r[i];
            }
        }
    }
    cout << min_l + 1 << ' ' << min_r + 1 << endl;
    return 0;
}
