#include <iostream>
using namespace std;

namespace DS{
    const int MAX = 32768;
    int v[MAX];
    int stack_sz[MAX], under_sz[MAX];
    void init(){
        for(int i = 0 ; i < MAX ; i++)
            v[i] = i, stack_sz[i] = 1, under_sz[i] = 0;
    }
    int find(int x){
        if(x != v[x]){
            int vx = find(v[x]);
            under_sz[x] += under_sz[v[x]];
            v[x] = vx;
        }
        return v[x];
    }
    void merge(int x, int y){
        x = find(x);
        y = find(y);
        under_sz[x] += stack_sz[y];
        stack_sz[y] += stack_sz[x];
        stack_sz[x] = 0;
        v[x] = y;
    }
};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    DS::init();
    char s[2];
    int a, b;
    cin >> n;
    while(n--){
        cin >> s;
        if(s[0] == 'M'){
            cin >> a >> b;
            DS::merge(a, b);
        } else {
            cin >> a;
            cout << DS::under_sz[a] << endl;
        }
        for(int i = 0 ; i < 10 ; i++) DS::find(i);
        for(int i = 0 ; i < 10 ; i++)
            cout << DS::stack_sz[i] << ' ';
        cout << endl;
        for(int i = 0 ; i < 10 ; i++)
            cout << DS::under_sz[i] << ' ';
        cout << endl;
    }
}
