#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main(int argc, char **argv){
    int start = 0;
    int end = 100;
    if(argc == 2)
        end = atoi(argv[1]);
    else if(argc == 3){
        start = atoi(argv[1]);
        end = atoi(argv[2]);
    }
    for(int i = start ; i < end ; i++){
        cout << i << endl;
        sleep(1);
    }
    return 0;
}
