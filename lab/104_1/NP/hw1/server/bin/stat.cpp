#include <sys/stat.h>
#include <bits/stdc++.h>
using namespace std;


bool can_exec(const char *file)
{
    struct stat  st;

    if (stat(file, &st) < 0)
        return false;
    if ((st.st_mode & S_IEXEC) != 0)
        return true;
    return false;
}


int main(){
    cout << can_exec("mylsr") << endl;
}
