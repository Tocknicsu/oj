#include <iostream>
#include <iomanip>
#include <vector>
#include "polynomial.h"

int main()
{
    polynomial p, q;
    std::cin >> p; // Input: 1 0 1
    std::cin >> q; // Input: -1 2 3 2 0

    {
        polynomial r(p); // Copy constructor
        r = q; // Copy assignment
    } // Destructor

    {
        std::cout << p << std::endl; // 1 0 1
        std::cout << q << std::endl; // -1 2 3 2
        std::cout << p + q << std::endl; // 0 2 4 2
        std::cout << p - q << std::endl; // 2 -2 -2 -2
        std::cout << p * q << std::endl; // -1 2 2 4 3 2
        std::cout << std::boolalpha << (p == q) << std::endl; // false
        std::cout << p.degree() << std::endl; // 2
        std::cout << q.degree() << std::endl; // 3
        std::cout << p.derivate() << std::endl; // 0 2
        std::cout << q.derivate() << std::endl; // 2 6 6
        std::cout << p(1.0) << std::endl; // 2
        std::cout << q(2.5) << std::endl; // 54
        if (p) {
            std::cout << std::boolalpha << static_cast<bool>(polynomial(0)) << std::endl; // false
        }
    }

        std::vector<int> v(10, 1);
        // p += v; // Error
        p += polynomial(v);
        std::cout << p << std::endl; // 2 1 2 1 1 1 1 1 1 1 

        
    {
        q *= 3;
        std::cout << q << std::endl; // -3 6 9 6
        polynomial r = -(q -= p);
        std::cout << q << std::endl; // -5 5 7 5 -1 -1 -1 -1 -1 -1
        std::cout << r << std::endl; // 5 -5 -7 -5 1 1 1 1 1 1
    }

    {
        std::vector<int> v(1000000, 1), u(1000000, 42);
        std::cout << std::boolalpha << static_cast<bool>(polynomial(v) * polynomial(42) - polynomial(u)) << std::endl; // false
    }

    return 0;
}
