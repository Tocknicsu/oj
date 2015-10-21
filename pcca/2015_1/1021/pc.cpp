#include <bits/stdc++.h>
using namespace std;
vector<string> vec;

void Solve(){
    string str;
    cin >> str;
    vector<int> dp(str.size()+1);
    dp[0] = 1;
    for(int i = 1 ; i <= (int)str.size() ; i++){
        for(int j = 0 ; j < (int)vec.size() ; j++){
            if(vec[j].size() == 2){
                if(i == 1) continue;
                dp[i] |= str[i-2] == vec[j][0] && str[i-1] == vec[j][1] && dp[i-2];
            } else {
                dp[i] |= str[i-1] == vec[j][0] && dp[i-1];
            }
        }
    }
    cout << (dp[str.size()] ? "YES" : "NO") << endl;
}

int main(){
    vec.push_back("h");
    vec.push_back("li");
    vec.push_back("na");
    vec.push_back("k");
    vec.push_back("rb");
    vec.push_back("cs");
    vec.push_back("fr");

    vec.push_back("be");
    vec.push_back("mg");
    vec.push_back("ca");
    vec.push_back("sr");
    vec.push_back("ba");
    vec.push_back("ra");


    vec.push_back("sc");
    vec.push_back("y");

    vec.push_back("ti");
    vec.push_back("zr");
    vec.push_back("hf");
    vec.push_back("rf");

    vec.push_back("v");
    vec.push_back("nb");
    vec.push_back("ta");
    vec.push_back("db");

    vec.push_back("cr");
    vec.push_back("mo");
    vec.push_back("w");
    vec.push_back("sg");


    vec.push_back("mn");
    vec.push_back("tc");
    vec.push_back("re");
    vec.push_back("bh");

    vec.push_back("fe");
    vec.push_back("ru");
    vec.push_back("os");
    vec.push_back("hs");

    vec.push_back("co");
    vec.push_back("rh");
    vec.push_back("ir");
    vec.push_back("mt");

    vec.push_back("ni");
    vec.push_back("pd");
    vec.push_back("pt");
    vec.push_back("ds");

    vec.push_back("cu");
    vec.push_back("ag");
    vec.push_back("au");
    vec.push_back("rg");

    vec.push_back("zn");
    vec.push_back("cd");
    vec.push_back("hg");
    vec.push_back("cn");

    vec.push_back("b");
    vec.push_back("al");
    vec.push_back("ga");
    vec.push_back("in");
    vec.push_back("ti");

    vec.push_back("c");
    vec.push_back("si");
    vec.push_back("ge");
    vec.push_back("sn");
    vec.push_back("pb");
    vec.push_back("fl");

    vec.push_back("n");
    vec.push_back("p");
    vec.push_back("as");
    vec.push_back("sb");
    vec.push_back("bi");

    vec.push_back("o");
    vec.push_back("s");
    vec.push_back("se");
    vec.push_back("te");
    vec.push_back("po");
    vec.push_back("lv");

    vec.push_back("f");
    vec.push_back("cl");
    vec.push_back("br");
    vec.push_back("i");
    vec.push_back("at");

    vec.push_back("he");
    vec.push_back("ne");
    vec.push_back("ar");
    vec.push_back("kr");
    vec.push_back("xe");
    vec.push_back("rn");

    vec.push_back("la");
    vec.push_back("ce");
    vec.push_back("pr");
    vec.push_back("nd");
    vec.push_back("pm");
    vec.push_back("sm");
    vec.push_back("eu");
    vec.push_back("gd");
    vec.push_back("tb");
    vec.push_back("dy");
    vec.push_back("ho");
    vec.push_back("er");
    vec.push_back("tm");
    vec.push_back("yb");
    vec.push_back("lu");

    vec.push_back("ac");
    vec.push_back("th");
    vec.push_back("pa");
    vec.push_back("u");
    vec.push_back("np");
    vec.push_back("pu");
    vec.push_back("am");
    vec.push_back("cm");
    vec.push_back("bk");
    vec.push_back("cf");
    vec.push_back("es");
    vec.push_back("fm");
    vec.push_back("md");
    vec.push_back("no");
    vec.push_back("lr");

    int n;
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while(n--)
        Solve();

    return 0;
}
