#include <iostream>

/*
считаем, что числитель и знаменатель в дробях 
могут быть строго целочисленными
*/

// функция нахождения НОД с помощью алгоритма Евклида
template <typename T>
int gcd (T a, T b) {
	while (b) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}

// create a teamplate for numerator and denominator type
// it can be int, short, long, double, float etc
template <typename T> class Fraction
{
    T numerator_;
    T denominator_;

    public:

    // default initialisation + direct initialisation
    Fraction(const T& N = 1, const T& D = 1) : numerator_(N), denominator_(D)
    {
        if (D == 0) 
            throw std::exception();
        // std::cout << "Constructor is called for [" << this << "] " << std::endl;
    }
    // copy constructor
    Fraction(const Fraction& frac) : numerator_(frac.numerator_), denominator_(frac.denominator_) {}
    // assignment operator
    Fraction& operator=(const Fraction& frac)
    {
        if (this == &frac) {return *this;}
        numerator_ = frac.numerator_;
        denominator_ = frac.denominator_;
        return *this;
    }
    ~Fraction()
    {
        // std::cout << "Distructor is called for [" << this << "] " << std::endl;
    }

    T get_numerator()
    {
        return numerator_;
    }
    T get_denominator()
    {
        return denominator_;
    }

    // упрощение дроби
    const Fraction Simplification()
    {
        T GCD = gcd(numerator_, denominator_);
        T numerator = numerator_ / GCD;
        T denominator = denominator_ / GCD;
        return Fraction(numerator, denominator);
    }

    //-------------------------------------overloading of operators-------------------------------------

    // overload operator '+' by value
    const Fraction operator+(const T& value)
    {
        T numerator = numerator_ + value*denominator_;
        return Fraction(numerator, this->denominator_).Simplification();        
    }
    // overload operator '+' by another fraction
    const Fraction operator+(const Fraction& frac)
    {
        T numerator = numerator_ * frac.denominator_ + frac.numerator_*denominator_;
        T denominator = denominator_ * frac.denominator_;
        return Fraction(numerator, denominator).Simplification();
    }

    // overload operator '-' by value
    const Fraction operator-(const T& value)
    {
        T numerator = value * denominator_;
        return Fraction(numerator, this->denominator_).Simplification();        
    }
    // overload operator '-' by another fraction
    const Fraction operator-(const Fraction& frac)
    {
        T numerator = numerator_*frac.denominator_ - frac.numerator_*denominator_;
        T denominator = denominator_ * frac.denominator_;
        return Fraction(numerator, denominator).Simplification();
    }

    const Fraction operator*(const T& value)
    {
        T numerator = numerator_ * value;
        return Fraction(numerator, this->denominator_).Simplification();
    }
    const Fraction operator*(const Fraction& frac)
    {
        T numinator = numerator_ * frac.numerator_;
        T denaminator = denominator_ * frac.denominator_;
        return Fraction(numinator, denaminator).Simplification();
    }

    const Fraction operator/(const T& value)
    {
        if (value == 0)
            throw std::exception(); 
        T denaminator = denominator_ * value;
        return Fraction(this->numerator_, denaminator);
    }
    const Fraction operator/(const Fraction& frac)
    {
        if (frac.numerator_ == 0) 
            throw std::exception();

        T numinator = numerator_ * frac.denominator_;
        T denaminator = denominator_ * frac.numerator_;
        return Fraction(numinator, denaminator).Simplification();
    }

};

// overloading of operator '<<' for members of class Fraction
template <typename T>
std::ostream& operator<<(std::ostream& out, Fraction<T>& obj)
{
    out << "(" << obj.get_numerator() << ")/(" << obj.get_denominator() << ")";
    return out;
}