#include <bits/stdc++.h>
#include <msgpack.hpp>
#include <sys/types.h>
#include <sys/stat.h>
#include <msgpack/fbuffer.hpp>
using namespace std;

int main(){
    FILE *fpIn, *fpOut;
    char *pTok, c;
    int p = 2, num_tests;
    vector<int> NUMBERS;
    msgpack::sbuffer sbuf;
    msgpack::unpacked result;
    struct stat st;
    size_t off = 0;
    stat("input.txt", &st);
    char *buf = new char[st.st_size];

    fpIn = fopen("input.txt", "rb");
    fread(buf, st.st_size, 1, fpIn);
    fclose(fpIn);

    msgpack::unpack(result, buf, st.st_size, off);
//    result.get().convert(num_tests);

    for(int k = 0 ; k < num_tests ; k++){
        msgpack::unpack(result, buf, st.st_size, off);
        result.get().convert(NUMBERS);
        sort(NUMBERS.begin(), NUMBERS.end());
        msgpack::pack(&sbuf, NUMBERS);
    }
    fpOut = fopen("output.txt", "wb");
    fwrite(sbuf.data(), sbuf.size(), 1, fpOut);
    fclose(fpOut);

    delete [] buf;

    return 0;
}
