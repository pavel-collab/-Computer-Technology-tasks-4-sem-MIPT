#include <iostream>
#include <cmath> // for floor
#include <numeric> // for std::gcd 
#include <exception> // for exceptions
#include <stdexcept> // for exceptions types
#include <utility> // for std::rel_ops
#include <gtest/gtest.h>

#include "../include/frac_class.hpp"

TEST(ClassFraction, FractionGetters)
{   
    Fraction<int> a(1, 2);
    Fraction<short> b(3, 5);
    Fraction<long> x;
    Fraction<long long> y(2000000000, 40000000000);
    Fraction<int32_t> t(123, 76);
    Fraction<unsigned> m(10, 100);

    // --------------------------------------------------------------------------------------------
    ASSERT_EQ(a.get_numerator(), 1);
    ASSERT_EQ(a.get_denominator(), 2);
    // --------------------------------------------------------------------------------------------
    ASSERT_EQ(b.get_numerator(), 3);
    ASSERT_EQ(b.get_denominator(), 5);
    // --------------------------------------------------------------------------------------------
    ASSERT_EQ(x.get_numerator(), 1);
    ASSERT_EQ(x.get_denominator(), 1);
    // --------------------------------------------------------------------------------------------
    ASSERT_EQ(y.get_numerator(), 1);
    ASSERT_EQ(y.get_denominator(), 20);
    // --------------------------------------------------------------------------------------------
    ASSERT_EQ(t.get_numerator(), 123);
    ASSERT_EQ(t.get_denominator(), 76);
    // --------------------------------------------------------------------------------------------
    ASSERT_EQ(m.get_numerator(), 1);
    ASSERT_EQ(m.get_denominator(), 10);
    // --------------------------------------------------------------------------------------------
}

TEST(ClassFraction, FractionBasicOperators)
{
    Fraction<int> a(2, 3);
    Fraction<int> b(3, 4);
    Fraction<int> x(1, 2);
    Fraction<int> y(8, 5);

    a+=1;
    ASSERT_EQ(a, Fraction<int>(5, 3));
    a-=1;
    ASSERT_EQ(a, Fraction<int>(2, 3));
    a*=5;
    ASSERT_EQ(a, Fraction<int>(10, 3));
    b/=3;
    ASSERT_EQ(b, Fraction<int>(1, 4));

    a += b;
    ASSERT_EQ(a, Fraction<int>(43, 12));
    x -= b;
    ASSERT_EQ(x, Fraction<int>(1, 4));
    x *= b;
    ASSERT_EQ(x, Fraction<int>(1, 16));
    x /= y;
    ASSERT_EQ(x, Fraction<int>(5, 16*8));
}

TEST(ClassFraction, FractionUnarOperators)
{
    Fraction<int64_t> a(1, 15);
    Fraction<int64_t> b(25, 3);

    ++a;
    ASSERT_EQ(a, Fraction<int64_t>(16, 15));
    ASSERT_EQ(a++, Fraction<int64_t>(31, 15));
    ++b;
    ASSERT_EQ(b, Fraction<int64_t>(28, 3));
    ASSERT_EQ(b++, Fraction<int64_t>(31, 3));

}

TEST(ClassFraction, FractionBinarOperators)
{
    Fraction<short> a(1, 2);
    Fraction<short> b(2, 3);
    Fraction<short> d(5, 3);
    Fraction<short> c(9, 10);

    auto x = b + 3;
    auto y = a - 1;
    auto z = d * 3;
    auto t = c / 9;
    EXPECT_EQ(x, Fraction<short>(11, 3));
    EXPECT_EQ(y, Fraction<short>(-1, 2));
    EXPECT_EQ(z, Fraction<short>(5, 1));
    EXPECT_EQ(t, Fraction<short>(1, 10));

    auto m = y / x;
    EXPECT_EQ(m, Fraction<short>(-3, 22));
    auto n = d + c;
    EXPECT_EQ(n, Fraction<short>(77, 30));
    auto r = x - y;
    EXPECT_EQ(r, Fraction<short>(25, 6));
    auto p = y * d;
    EXPECT_EQ(p, Fraction<short>(-5, 6));
}

TEST(ClassFraction, FractionCompareOperators)
{
    Fraction<int> a(1, 2);
    Fraction<int> b(1, 3);

    EXPECT_TRUE(a != b) << "\x1b[33mError_mes\x1b[0m";
    auto x = a / 3;
    auto y = b / 2;
    EXPECT_TRUE(x == y) << "\x1b[33mError_mes\x1b[0m";
    EXPECT_TRUE(a > b) << "\x1b[33mError_mes\x1b[0m";
    x = a - 1;
    EXPECT_TRUE(x < b) << "\x1b[33mError_mes\x1b[0m";
    EXPECT_TRUE(a >= a) << "\x1b[33mError_mes\x1b[0m";
    EXPECT_TRUE(b <= b) << "\x1b[33mError_mes\x1b[0m";

	EXPECT_FALSE(a < b) << "\x1b[33mError_mes\x1b[0m";
    EXPECT_FALSE(a > a++) << "\x1b[33mError_mes\x1b[0m";
}

TEST(ClassFraction, FractionOtherMethods)
{
    Fraction<unsigned> a(1, 2);
    Fraction<int> b(-5, 20);

    EXPECT_EQ(a.decimal(), 0.5);
    EXPECT_EQ(b.decimal(), -0.25);

    double x = 0.125;
    double y = 0.3;
    double z = 0.203;

    Fraction<int> t;

    ASSERT_EQ(t.dec_to_reg(x), Fraction<int>(1, 8));
    ASSERT_EQ(t.dec_to_reg(y), Fraction<int>(3, 10));
    ASSERT_EQ(t.dec_to_reg(z), Fraction<int>(203, 1000));
}