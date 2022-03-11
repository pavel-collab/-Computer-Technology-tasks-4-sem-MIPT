//* compile with: g++ -std=c++17 main.cpp
#include <iostream>
#include <numeric> // for std::gcd
#include <cmath> // for floor
#include "frac_class.hpp"

/*
считаем, что числитель и знаменатель в дробях 
могут быть строго целочисленными
*/

int main()
{   

    try
    {
        Fraction<int> x(3, 4);
        // Fraction<int> y(2, 3);
        Fraction<int> z;
        // Fraction<int> a(5, 10);
        z = x + 5;

        // std::cout << "a = " << a << std::endl;
        std::cout << "x = " << x << std::endl;
        // std::cout << "y = " << y << std::endl;
        std::cout << "z = " << z << std::endl;
        double k = z.decimal();
        std::cout << k << std::endl;

        double p = 6.25;
        Fraction<int> a;

        std::cout << a.dec_to_reg(p) << std::endl;

        // auto t = z + y;
        // auto m = x - z;
        // auto n = y * x;

        // std::cout << "t = " << t << std::endl;
        // std::cout << "m = " << m << std::endl;
        // std::cout << "n = " << n << std::endl;
        // std::cout << "n = " << n << std::endl;

        // x = x * y;
        // std::cout << "x = " << x << std::endl;

        // auto k = x / 0; // terrible wrong
        // std::cout << "k = " << k << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    return 0;
}
