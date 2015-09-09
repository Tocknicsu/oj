#include <bits/stdc++.h>
using namespace std;

string int2str = "mjqhofawcpnsexdkvgtzblryui";
string str2int = "uzrmatifxopnhwvbslekycqjgd";
void Solve(){
    int n, ans=0;
    cin >> n;
    string str;
    for(int i = 0 ; i < n ; i++){
        cin >> str;
        if(isdigit(str[0])){
            int tmp = str[0]-'0';
            if(str.size()==2){
                tmp = tmp * 10 + str[1] - '0';
            }
            cout << int2str[tmp-1];
        } else {
            for(int i = 0 ; i < 26 ; i++)
                if(str2int[i]==str[0])
                    ans += i + 1;

        }
    }
    if(ans)
        cout << ans;
    cout << endl;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        Solve();
    return 0;
}
