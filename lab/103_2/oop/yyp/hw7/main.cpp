#include "msgpack.hpp"
#include <stdio.h>

#include <cassert>
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

int main() {
    using std::int64_t;

    // v1 = nil
    puts("part 1");
    const value v1;
    assert(v1.is_nil());
    assert(!v1.is_boolean());
    assert(!v1.is_integer());
    assert(!v1.is_string());
    assert(!v1.is_array());
    assert(!v1.is_map());
    puts("part 1");

    // v2 = true
    puts("part 2");
    const value v2(true);
    assert(v2.is_boolean());
    assert(v2.get_boolean());
    try {
        v2.get_integer();
        assert(false); // should not reach here
    } catch (const std::bad_cast&) {}
    puts("part 2");

    // v3 = "hello world"
    puts("part 3");
    value v3(std::string("hello"));
    assert(v3.is_string());
    v3.get_string() += " world";
    puts("part 3");

    // v4 = [true, 42]
    puts("part 4");
    std::vector<value> v;
    v.push_back(value(true));
    v.push_back(value(int64_t(42)));
    value v4(v);
    assert(v4.is_array());
    assert(v4.get_array()[0].get_boolean());
    assert(v4.get_array()[1].get_integer() == 42);
    puts("part 4");
    
    // v5 = {"a": false}
    puts("part 5");
    value v5 = value(value::map_type());
    assert(v5.is_map());
    v5.get_map()["a"] = value(false);
    assert(v5.get_map().size() == 1);
    assert(!v5.get_map()["a"].get_boolean());
    puts("part 5");

    // v6 = {"a": [0, 42], "b": "test"}
    puts("part 6");
    value v6 = v5;
    v6.get_map()["a"] = v4;
    v6.get_map()["b"] = value(std::string("test"));
    puts("part 6");

    // Serialize nil
    {
        puts("part 7");
        std::stringstream ss;
        v1.serialize(ss);
        assert(ss.str() == "\xc0");
        puts("part 7");
    }
    
    // Serialize true
    {
        puts("part 8");
        std::stringstream ss;
        v2.serialize(ss);
        assert(ss.str() == "\xc3");
        puts("part 8");
    }
    
    // Serialize "hello world"
    {
        puts("part 9");
        std::stringstream ss;
        v3.serialize(ss);
        const std::vector<std::uint8_t> ans = {
             0xdb, // type: string
             0x00, 0x00, 0x00, 0x0b, // length: 11
             0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x77, 0x6f, 0x72, 0x6c, 0x64 // "hello world"
        };
        assert(std::equal(std::istreambuf_iterator<char>(ss), std::istreambuf_iterator<char>(), ans.begin(), std::equal_to<std::uint8_t>()));
        puts("part 9");
    }

    // Serialize [true, 42]
    {
        puts("part 10");
        std::stringstream ss;
        v4.serialize(ss);
        const std::vector<std::uint8_t> ans = {
            0xdd, // type: array
            0x00, 0x00, 0x00, 0x02, // length: 2
            0xc3, // type: bool, true
            0xd3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2a // type: 64-bit int, 42
        };
        assert(std::equal(std::istreambuf_iterator<char>(ss), std::istreambuf_iterator<char>(), ans.begin(), std::equal_to<std::uint8_t>()));
        puts("part 10");
    }

    // Serialize {"a": false}
    {
        puts("part 11");
        std::stringstream ss;
        v5.serialize(ss);
        const std::vector<std::uint8_t> ans = {
            0xdf, // type: map
            0x00, 0x00, 0x00, 0x01, // length: 1
            0xdb, 0x00, 0x00, 0x00, 0x01, 0x61, // type: string, length: 1, "a"
            0xc2 // type: bool, true
        };

        assert(std::equal(std::istreambuf_iterator<char>(ss), std::istreambuf_iterator<char>(), ans.begin(), std::equal_to<std::uint8_t>()));
        puts("part 11");
    }

    // Serialize {"a": [0, 42], "b": "test"}
    {
        std::stringstream ss;
        v6.serialize(ss);
        const std::vector<std::uint8_t> ans = {
            0xdf, // type: map
            0x00, 0x00, 0x00, 0x02, // length: 2

            0xdb, 0x00, 0x00, 0x00, 0x01, 0x61, // type: string, length: 1, "a"
            0xdd, // type: array
            0x00, 0x00, 0x00, 0x02, // length: 2
            0xc3, // type: bool, true
            0xd3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2a, // type: 64-bit int, 42

            0xdb, 0x00, 0x00, 0x00, 0x01, 0x62, // type: string, length: 1, "b"
            0xdb, 0x00, 0x00, 0x00, 0x04, 0x74, 0x65, 0x73, 0x74, // type: string, length: 4, "test"
        };
        fflush(stdout);
        assert(std::equal(std::istreambuf_iterator<char>(ss), std::istreambuf_iterator<char>(), ans.begin(), std::equal_to<std::uint8_t>()));
    }

    // Deserialize into "test"
    {
        puts("part 13");
        std::stringstream ss;
        const std::vector<std::uint8_t> input = {
            0xdb, 0x00, 0x00, 0x00, 0x04, 0x74, 0x65, 0x73, 0x74, // type: string, length: 4, "test"
        };
        for (size_t i = 0; i < input.size(); ++i) {
            ss << input[i];
        }
        const value v = value::deserialize(ss);
        assert(v.is_string());
        assert(v.get_string() == "test");
        puts("part 13");
    }
    // Serialize and then deserialize
    {
        puts("part 14");
        std::stringstream ss;
        v6.serialize(ss);
        const value v = value::deserialize(ss);
        assert(v == v6);
        puts("part 14");
    }
    
    // Deserialization failure
    {
        puts("part 15");
        std::stringstream ss;
        ss << '\xff'; // undefined tag
        const value v = value::deserialize(ss);
        assert(v.is_nil());
        assert(ss.fail());
        puts("part 15");
    }
    
    // undefined tag
    {
        puts("part 16");
        std::stringstream ss;
        ss << "\xdd";
        for(int i=0;i<3;i++)ss << '\x00';
        ss << "\x01\x12";
        const value v = value::deserialize(ss);
        assert(v.is_nil());
        assert(ss.fail());
        puts("part 16");
    }

    //stress test
    {
        puts("part 17");
        int start = clock();
        map<value::string_type, value> mp;
        vector<value> vc;
        for(int i=0;i<10;i++){
            mp[to_string(i)] = value(vc);
            vc.push_back(value(mp)); 
        }
        stringstream ss;
        value v7(mp);
        v7.serialize(ss);
        value res = value::deserialize(ss);
        assert(v7 == res);
        assert(v7 == v7);
        printf("time: %f\n",(double)(clock()-start)/CLOCKS_PER_SEC);
        puts("part 17");
    }

    {
        puts("part 18");
        int start = clock();
        map<value::string_type, value> mp;
        for(int i=0;i<13;i++){
            mp[to_string(i)] = value(mp);
        }
        stringstream ss;
        value v(mp);
        v.serialize(ss);
        value res = value::deserialize(ss);
        assert(v == res);
        printf("time: %f\n",(double)(clock()-start)/CLOCKS_PER_SEC);
        puts("part 18");
    }

    // undefined tag
    {
        puts("part 19");
        std::stringstream ss;
        ss << "\xdd";
        for(int i=0;i<3;i++)ss << '\x00';
        ss << "\x01\xc2\xc3";
        const value v = value::deserialize(ss);
        assert(v.is_nil());
        assert(ss.fail());
        puts("part 19");
    }

    // self assignment
    {
        puts("part 20");
        value a(true);
        assert(a.is_boolean());
        a = a;
        assert(a.is_boolean());
        a = value(string(""));
        assert(a.is_string());
        a = a;
        assert(a.is_string());
        a = value(map<value::string_type, value>());
        assert(a.is_map());
        a = a;
        assert(a.is_map());
        a = value();
        assert(a.is_nil());
        a = a;
        assert(a.is_nil());
        puts("part 20");
    }
    return 0;
}
