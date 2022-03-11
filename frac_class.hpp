#include <iostream>
#include <cmath> // for floor
#include <numeric> // for std::gcd 

#include <exception>
#include <stdexcept>

// точность перевода из числа с плавающей точкой в обычную дробь
#define ACCURACY 1e-8

/*
считаем, что числитель и знаменатель в дробях 
могут быть строго целочисленными
*/

// create a template for numerator and denominator type
// it can be int, short, long etc
template <typename T> class Fraction
{
    T numerator_;
    T denominator_;

    public:

    // default initialisation + direct initialisation
    Fraction(const T& N = 1, const T& D = 1) : numerator_(N), denominator_(D)
    {
        if (D == 0) 
            throw std::runtime_error("Division by zero!");
        T GCD = std::gcd(numerator_, denominator_);
        numerator_ = numerator_ / GCD;
        denominator_ = denominator_ / GCD;
    }

    // getters
    const T get_numerator()   const { return numerator_; }
    const T get_denominator() const { return denominator_; }

    //-------------------------------------overloading of binary operators-------------------------------------

    /*
    We're don't overload operations +, -, * and / by value,
    cause this operations are realized by compilator with implicit type casting
    */

    // overload operator '+' by another fraction
    const Fraction operator+(const Fraction& frac)
    {
        T numerator = numerator_ * frac.denominator_ + frac.numerator_*denominator_;
        T denominator = denominator_ * frac.denominator_;
        return Fraction(numerator, denominator);
    }

    // overload operator '-' by another fraction
    const Fraction operator-(const Fraction& frac)
    {
        T numerator = numerator_*frac.denominator_ - frac.numerator_*denominator_;
        T denominator = denominator_ * frac.denominator_;
        return Fraction(numerator, denominator);
    }

    // overload operator '*' by another fraction
    const Fraction operator*(const Fraction& frac)
    {
        T numinator = numerator_ * frac.numerator_;
        T denaminator = denominator_ * frac.denominator_;
        return Fraction(numinator, denaminator);
    }

    // overload operator '/' by another fraction
    const Fraction operator/(const Fraction& frac)
    {
        if (frac.numerator_ == 0) 
            throw std::runtime_error("Division by zero!");

        T numinator = numerator_ * frac.denominator_;
        T denaminator = denominator_ * frac.numerator_;
        return Fraction(numinator, denaminator);
    }

    // overload operator '++'
    const Fraction& operator++() 
    {
        *this = *this + 1;
        return *this;
    }
    // overload operator '--'
    const Fraction& operator--() 
    {
        *this = *this - 1;
        return *this;
    }
    // overload operator '+='
    const Fraction& operator+=(const Fraction& frac) 
    {
        *this = *this + frac;
        return *this;
    }
    // overload operator '-='
    const Fraction& operator-=(const Fraction& frac) 
    {
        *this = *this - frac;
        return *this;
    }
    // overload operator '*='
    const Fraction& operator*=(const Fraction& frac) 
    {
        *this = *this * frac;
        return *this;
    }
    // overload operator '/='
    const Fraction& operator/=(const Fraction& frac) 
    {
        if (frac.numerator_ == 0) 
            throw std::runtime_error("Division by zero!");
        *this = *this / frac;
        return *this;
    }

    // приведение обычной дроби к десятичной типа float
    double decimal() const { return static_cast<double>(numerator_) / denominator_; }

    const Fraction dec_to_reg(const double& dec) 
    {
        double tmp = dec;
        int whole_part = static_cast<int>(floor(tmp));
        double frac_part = dec - whole_part;

        int cntr = 1;
        while(frac_part > ACCURACY && cntr < 1e8) {
            cntr *= 10;
            frac_part *= 10;
            frac_part -= floor(frac_part);
        }

        Fraction A{static_cast<T>((dec - whole_part) * cntr), cntr};
        A = A + whole_part;

        // *this = A;
        return A;
    }
};

// overloading of operator '<<' for members of class Fraction
template <typename T>
std::ostream& operator<<(std::ostream& out, const Fraction<T>& obj)
{
    out << "(" << obj.get_numerator() << ")/(" << obj.get_denominator() << ")";
    return out;
}

//! когда пытаюсь поставить в конструкторе assert или условие или кинуть ислючение
//! на предмет std::is_integral<T>::value == false, компилятор опережает
//! и генерит ошибку компиляции в связи с использованием std::gcd
//! другими словами компилятор слишком умный и одновременно слишком тупой, чтобы понять, что
//! я самостоятельно отслеживаю нужный тип данных

//* Поменял собственную написанную функцию gcd на ту же функцию стандартной библиотеки
//* убрал некоторые опечатки в комментариях
//* убрал копирующий конструктор и оператор присваивания, ибо компилятор реализует его по умолчанию
//* перенес сокращение дроби в конструктор, убрал отдельный метод, отвечающий за это (по ненадобности)
//* убрал все перегруженные операторы, реализующие взаимодействие дроби с числом (компилятор сделает это за нас)
//* добавил метод приведения дроби Fraction к десятичному числу типа double
//* добавил метод приведения числа с плавающей точкой типа double к объекту класса Fraction
//* перегрузил дополнительные операторы (++, --, +=, -=, *=, /=)
//* улучшил исключения: нашел нужный тип класса exception

//TODO: перегрузить операторы сравнения
//TODO: написать gtests
//TODO: написать для них CMake file