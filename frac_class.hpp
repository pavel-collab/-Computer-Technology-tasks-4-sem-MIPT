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

// create a teamplate for numenator and denumenator type
// it can be int, short, long, double, float etc
template <typename T> class Fraction
{
    T numenator_;
    T denamenator_;

    public:

    // default initialisation + direct initialisation
    Fraction(const T& N = 1, const T& D = 1) : numenator_(N), denamenator_(D)
    {
        if (D == 0) 
            throw std::exception();
        // std::cout << "Constructor is called for [" << this << "] " << std::endl;
    }
    // copy constructor
    Fraction(const Fraction& frac) : numenator_(frac.numenator_), denamenator_(frac.denamenator_) {}
    // assignment operator
    Fraction& operator=(const Fraction& frac)
    {
        if (this == &frac) {return *this;}
        numenator_ = frac.numenator_;
        denamenator_ = frac.denamenator_;
        return *this;
    }
    ~Fraction()
    {
        // std::cout << "Distructor is called for [" << this << "] " << std::endl;
    }

    T get_numenator()
    {
        return numenator_;
    }
    T get_denamenator()
    {
        return denamenator_;
    }

    // упрощение дроби
    const Fraction Simplification()
    {
        T GCD = gcd(numenator_, denamenator_);
        T numenator = numenator_ / GCD;
        T denamenator = denamenator_ / GCD;
        return Fraction(numenator, denamenator);
    }

    //-------------------------------------overloading of operators-------------------------------------

    // overload operator '+' by value
    const Fraction operator+(const T& value)
    {
        T numenator = numenator_ + value*denamenator_;
        return Fraction(numenator, this->denamenator_).Simplification();        
    }
    // overload operator '+' by another fraction
    const Fraction operator+(const Fraction& frac)
    {
        T numenator = numenator_ * frac.denamenator_ + frac.numenator_*denamenator_;
        T denamenator = denamenator_ * frac.denamenator_;
        return Fraction(numenator, denamenator).Simplification();
    }

    // overload operator '-' by value
    const Fraction operator-(const T& value)
    {
        T numenator = value * denamenator_;
        return Fraction(numenator, this->denamenator_).Simplification();        
    }
    // overload operator '-' by another fraction
    const Fraction operator-(const Fraction& frac)
    {
        T numenator = numenator_*frac.denamenator_ - frac.numenator_*denamenator_;
        T denamenator = denamenator_ * frac.denamenator_;
        return Fraction(numenator, denamenator).Simplification();
    }

    const Fraction operator*(const T& value)
    {
        T numenator = numenator_ * value;
        return Fraction(numenator, this->denamenator_).Simplification();
    }
    const Fraction operator*(const Fraction& frac)
    {
        T numinator = numenator_ * frac.numenator_;
        T denaminator = denamenator_ * frac.denamenator_;
        return Fraction(numinator, denaminator).Simplification();
    }

    const Fraction operator/(const T& value)
    {
        if (value == 0)
            throw std::exception(); 
        T denaminator = denamenator_ * value;
        return Fraction(this->numenator_, denaminator);
    }
    const Fraction operator/(const Fraction& frac)
    {
        if (frac.numenator_ == 0) 
            throw std::exception();

        T numinator = numenator_ * frac.denamenator_;
        T denaminator = denamenator_ * frac.numenator_;
        return Fraction(numinator, denaminator).Simplification();
    }

};

// overloading of operator '<<' for members of class Fraction
template <typename T>
std::ostream& operator<<(std::ostream& out, Fraction<T>& obj)
{
    out << "(" << obj.get_numenator() << ")/(" << obj.get_denamenator() << ")";
    return out;
}