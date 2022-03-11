//* compile with: g++ -std=c++17 main.cpp
#include <iostream>
#include <numeric> // for std::gcd
#include <cmath> // for floor
#include <exception>
#include <stdexcept>
#include "frac_class.hpp"

/*
считаем, что числитель и знаменатель в дробях 
могут быть строго целочисленными
*/

int main()
{   

    try
    {
        // Fraction<int> a(1, 0);
        Fraction<int> x(2, 4);
        x/=0;
    }
    catch(const std::runtime_error& err)
    {
        std::cerr << "Runtime error: " << err.what() << std::endl;
        exit(1);
    }

    return 0;
}
