#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("pb.in", "r", stdin);
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        vector<int> a(n), b(m);
        for(int i = 0 ; i < n ; i++)
            scanf("%d", &a[i]);
        for(int i = 0 ; i < m ; i++){
            scanf("%d", &b[i]);
        }
        vector<int> da, db;
        for(int i = 1 ; i < n ; i++)
            da.push_back(a[i] - a[i-1]);
        for(int i = 1 ; i < m ; i++)
            db.push_back(-(b[i] - b[i-1]));
        vector<int> f(n-1);
        f[0] = -1;
        int j = -1;
        for(int i = 1 ; i < n - 1 ; i++){
            while(j != -1 && da[i] != da[j+1]) j = f[j];
            if(da[i] == da[j+1]) j++;
            f[i] = j;
        }
        /*
        for(int i = 0 ; i < n - 1 ; i++)
            printf("%d ", f[i]);
        printf("\n");
        */
        int ans = 0;
        j = -1;
        for(int i = 0 ; i < m - 1 ; i++){
            while(j != -1 && db[i] != da[j+1]) j = f[j];
            if(db[i] == da[j+1]) j++;
            if(j == (int)da.size() - 1){
                ans++;
                j = f[j];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
