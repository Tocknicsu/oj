#include <iostream>
#include <string>
using namespace std;
string a, b;
void query(int al, int bl, int br){
    int id = bl;
    for( ; id < br ; ++id)
        if(b[id] == a[al])
            break;
    if(id - bl > 0)
        query(al+1, bl, id);
    if(br - id - 1 > 0)
        query(al+id-bl +1, id+1, br);
    cout << a[al];
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    while(cin >> a >> b){
        query(0, 0, b.size());
        cout << endl;
    }
}
