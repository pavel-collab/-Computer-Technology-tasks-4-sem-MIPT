#include <iostream>
#include <cmath> // for floor
#include <numeric> // for std::gcd 
#include <exception> // for exceptions
#include <stdexcept> // for exceptions types
#include <utility> // for std::rel_ops

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

    //-------------------------------------Constructor-------------------------------------

    Fraction(const T& N = 1, const T& D = 1) : numerator_(N), denominator_(D)
    {
        if (D == 0) 
            throw std::runtime_error("Division by zero!");
        T GCD = std::gcd(numerator_, denominator_);
        numerator_ = numerator_ / GCD;
        denominator_ = denominator_ / GCD;
    }

    //-------------------------------------getters-------------------------------------

    const T get_numerator()   const { return numerator_; }
    const T get_denominator() const { return denominator_; }

    //-------------------------------------overloading of operators (+=, -=, *=, /=)-------------------------------------

    // overload operator '+='
    const Fraction& operator+=(const Fraction& frac) 
    {
        numerator_= numerator_ * frac.denominator_ + frac.numerator_ * denominator_;
        denominator_= denominator_ * frac.denominator_;
        return *this;
    }
    // overload operator '-='
    const Fraction& operator-=(const Fraction& frac) 
    {
        numerator_= numerator_ * frac.denominator_ - frac.numerator_*denominator_;
        denominator_= denominator_ * frac.denominator_;
        return *this;
    }
    // overload operator '*='
    const Fraction& operator*=(const Fraction& frac) 
    {
        numerator_ = numerator_ * frac.numerator_;
        denominator_ = denominator_ * frac.denominator_;
        return *this;
    }
    // overload operator '/='
    const Fraction& operator/=(const Fraction& frac) 
    {
        if (frac.numerator_ == 0) 
            throw std::runtime_error("Division by zero!");
        numerator_ = numerator_ * frac.denominator_;
        denominator_ = denominator_ * frac.numerator_;
        return *this;
    }

    //-------------------------------------overloading of operators (++, --)-------------------------------------

    const Fraction& operator++() 
    {
        *this = *this += 1;
        return *this;
    }

    const Fraction& operator--() 
    {
        *this = *this -= 1;
        return *this;
    }

    const Fraction operator++(int) {
        Fraction temp = *this;
        ++temp;
        return temp;
    }

    const Fraction operator--(int) {
        Fraction temp = *this;
        --temp;
        return temp;
    }

    //-------------------------------------Some other class methods-------------------------------------

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

        return A;
    }
};

//-------------------------------------overloading of operators (==, !=, <, >, >=, <=)-------------------------------------

// базовые операторы сравнения
template <typename T>
bool operator==(const Fraction<T>& lh, const Fraction<T>& rh) { return lh.get_numerator() * rh.get_denominator() == rh.get_numerator() * lh.get_denominator(); }
template <typename T>
bool operator<(const Fraction<T>& lh, const Fraction<T>& rh) { return lh.get_numerator() * rh.get_denominator() < rh.get_numerator() * lh.get_denominator(); }
// зависимые операторы сравнения
template <typename T>
bool operator> (const Fraction<T>& lh, const Fraction<T>& rh)  { return std::rel_ops::operator>(lh, rh); }
template <typename T>
bool operator<=(const Fraction<T>& lh, const Fraction<T>& rh) { return std::rel_ops::operator<=(lh, rh); }
template <typename T>
bool operator>=(const Fraction<T>& lh, const Fraction<T>& rh) { return std::rel_ops::operator>=(lh, rh); }
template <typename T>
bool operator!=(const Fraction<T>& lh, const Fraction<T>& rh) { return std::rel_ops::operator!=(lh, rh); }

//-------------------------------------overloading of operator (<<)-------------------------------------

template <typename T>
std::ostream& operator<<(std::ostream& out, const Fraction<T>& obj)
{
    out << "(" << obj.get_numerator() << ")/(" << obj.get_denominator() << ")";
    return out;
}

//-------------------------------------overloading of operators (+, -, *, /)-------------------------------------

template <typename T, typename I>
const Fraction<T> operator+(const Fraction<T>& lhs, const I& rhs)
{
    Fraction<T> tmp{lhs};
    tmp += rhs;
    return tmp;
}

template <typename T, typename I>
const Fraction<T> operator-(const Fraction<T>& lhs, const I& rhs)
{
    Fraction<T> tmp{lhs};
    tmp -= rhs;
    return tmp;
}

template <typename T, typename I>
const Fraction<T> operator*(const Fraction<T>& lhs, const I& rhs)
{
    Fraction<T> tmp{lhs};
    tmp *= rhs;
    return tmp;
}

template <typename T, typename I>
const Fraction<T> operator/(const Fraction<T>& lhs, const I& rhs)
{
    Fraction<T> tmp{lhs};
    tmp /= rhs;
    return tmp;
}


//! когда пытаюсь поставить в конструкторе assert или условие или кинуть ислючение
//! на предмет std::is_integral<T>::value == false, компилятор опережает
//! и генерит ошибку компиляции в связи с использованием std::gcd
//! другими словами компилятор слишком умный и одновременно слишком тупой, чтобы понять, что
//! я самостоятельно отслеживаю нужный тип данных

//??? разобраться с std::is_integral
//??? реализация операторов сравнения вне тела класса
//??? не работают штучки 20го стандарта (#include <compare>)
//??? можно ли сделать описание метода класса вне тела класса (в теле класса только объявить функцию)
//??? std::rel_ops -- не лучше ли сделать using namespace std::rel_ops

//* Поменял собственную написанную функцию gcd на ту же функцию стандартной библиотеки
//* убрал некоторые опечатки в комментариях
//* убрал копирующий конструктор и оператор присваивания, ибо компилятор реализует его по умолчанию
//* перенес сокращение дроби в конструктор, убрал отдельный метод, отвечающий за это (по ненадобности)
//* убрал все перегруженные операторы, реализующие взаимодействие дроби с числом (компилятор сделает это за нас)
//* добавил метод приведения дроби Fraction к десятичному числу типа double
//* добавил метод приведения числа с плавающей точкой типа double к объекту класса Fraction
//* перегрузил дополнительные операторы (++, --, +=, -=, *=, /=)
//* улучшил исключения: нашел нужный тип класса exception
//* перегрузил операторы сравнения
//* написал CMakeLists
//* написал тесты, но некоторые пока не работают (файлятся)

//! переписал перегрузку операторов: теперь бинарные операторы перегружены вне класса потому что это не методы:
//! они принимают 2 атрибута, но при этом перестало работать автоматическое сокращение

//TODO: написать нормальные gtests