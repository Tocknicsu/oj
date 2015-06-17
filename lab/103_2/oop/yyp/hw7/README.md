Hint
========
下面這段code可以用來檢查你的serialize有沒有寫對<br>

```c
#include <iomanip>
using namespace std;
void print(value &v){
    stringstream ss;
    v.serialize(ss);
    string str;
    getline(ss, str);
    for(int i = 0 ; i < (int)str.size() ; i++)
        cout << setw(2) << setfill('0') << hex << (((int)str[i])&255) << ' ';
    cout << endl;
}
```

關於輸出
----------
如果今天你要輸出ASCII碼為{num}的話<br>
你可以使用跳脫字元 ex: '\x{num}' or "\x{num}" <br>
或者是直接將他轉為char char({num}) <br>

舉個例子 如果你要輸出ASCII為123的字元(16進位為7b)<br>
你可以使用 out << char(123)
或者 out << '\x7b'

Failbit
------------
要怎麼使用可以去google<br>
這邊提示一下<br>
如果一個stream被拿去deserialize應該變成一個value<br>
如果你在parse的過程中<br>
發現tag不符 或者是 數量有少 ex: \0xd3(正常後面應該還要有8個bytes)<br>
就該設定stream的failbit<br>
~~~~以下不確定 已寄信去問助教了~~~~
又或者是你按照他給的tag parse完了<br>
可是這時候stream還沒讀到eof<br>
就代表他格式也不符 ex: \0xc2\0xc2


String
------------
關於string在serialize的時候<br>
如果中途遇到\x00('\0')<br>
就要結束<br>
換句話說<br>
如果"msg\x00pack"<br>
serialize之後應該會是<br>
db 00 00 00 03 6d 73 67<br>
而不是<br>
db 00 00 00 07 6d 73 67 70 61 63 6b<br>
```c++
    string str;
    str.push_back('m');
    str.push_back('s');
    str.push_back('g');
    str.push_back('\0');
    str.push_back('p');
    str.push_back('a');
    str.push_back('c');
    str.push_back('k');
    value _str(str);
    print(_str);
```


Endian.h
---------------
想想什麼時候需要用到他~
