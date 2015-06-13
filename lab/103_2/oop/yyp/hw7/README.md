Hint
========
下面這段code可以用來檢查你的serialize有沒有寫對<br>

```c
#include <iomanip>
using namespace std;
void print(stringstream &ss){
    string str;
    getline(ss, str);
    for(int i = 0 ; i < (int)str.size() ; i++)
        cout << setw(2) << setfill('0') << hex << (((int)str[i])&255) << ' ';
    ss.seekg(0, ss.beg);
    cout << endl;
}
```

關於輸出
----------
