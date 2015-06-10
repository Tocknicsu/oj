#include <cassert>
#include <cstdint>
#include <fstream>
#include <string>
#include <typeinfo>

#include "msgpack.hpp"

int main()
{
    const value v1(std::int64_t(1));
    assert(v1.is_integer());
    assert(v1.get_integer() == 1);

    value v2(std::string("msgpack"));
    assert(v2.is_string());

    try {
        v2.get_boolean();
        // should not reach here
    } catch (const std::bad_cast&) {}

    v2.get_string() = "hello";

    std::vector<value> a;
    a.push_back(value(true));
    a.push_back(v2);
    const value v3(a);
    assert(v3.is_array());

    {
        std::ofstream out("v3.bin");
        v3.serialize(out);
    }

    std::ifstream in("v3.bin");
    const value v4 = value::deserialize(in);
    assert(v3 == v4);

    return 0;
}
