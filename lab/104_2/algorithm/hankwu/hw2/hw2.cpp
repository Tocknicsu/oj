#include <msgpack.hpp>
#include <msgpack/vrefbuffer.hpp>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

void Read(msgpack::unpacker &unpacker, string filename){
    FILE *fpIn = fopen(filename.c_str(), "rb");
    fseek(fpIn, 0, SEEK_END);
    int filesize = ftell(fpIn);
    rewind(fpIn);

    unpacker.reserve_buffer(filesize);
    fread(unpacker.buffer(), filesize, 1, fpIn);
    unpacker.buffer_consumed(filesize);
    fclose(fpIn);
}
void Write(msgpack::sbuffer &sbuf, string filename){
    FILE *fpOut = fopen(filename.c_str(), "wb");
    fwrite(sbuf.data(), sbuf.size(), 1, fpOut);
    fclose(fpOut);
}

int main(){
    msgpack::unpacker unpacker;
    msgpack::unpacked result;
    msgpack::sbuffer sbuf;
    Read(unpacker, "input.txt");
    unpacker.next(&result);
    int tests;
    result.get().convert(tests);
    vector<int> vec;
    while(unpacker.next(&result)){
        result.get().convert(vec);
        sort(vec.begin(), vec.end());
        pack(&sbuf, vec);
    }
    Write(sbuf, "output.txt");
    return 0;
}

