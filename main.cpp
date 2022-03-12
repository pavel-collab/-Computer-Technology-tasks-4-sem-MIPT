//* compile with: g++ -std=c++17 main.cpp
#include <iostream>
#include <cmath> // for floor
#include <numeric> // for std::gcd 
#include <exception> // for exceptions
#include <stdexcept> // for exceptions types
#include <utility> // for std::rel_ops
#include "frac_class.hpp"

/*
считаем, что числитель и знаменатель в дробях 
могут быть строго целочисленными
*/

int main()
{   

    Fraction<int> a(2, 3);
    Fraction<int> b(3, 4);
    Fraction<int> x(5, 2);
    Fraction<int> y(10, 4);

    if (x == y) {
        puts("x == y");
    }
    if (a >= b) {
        puts("a >= b");
    }
    else {
        puts("a <= b");
    }

    try
    {
        Fraction<int> a(3, 4);
        Fraction<int> b(5, 2);

        std::cout << a << std::endl;

        auto r = a / b;
        std::cout << r << std::endl;
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Run time error: " << e.what() << '\n';
    }

    return 0;
}
