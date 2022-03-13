#! /usr/bin/env python3
from math import gcd

class Fraction:
    __slots__ = ['__numerator', '__denominator']

    #----------------------------------------------------Constructor----------------------------------------------------
    
    def __init__(self, N = 1, D = 1):
        if D == 0:
            raise ZeroDivisionError

        GCD = gcd(N, D)
        self.__numerator = int(N / GCD)
        self.__denominator = int(D / GCD)
        print("Constructor called")

    #----------------------------------------------------Getters----------------------------------------------------
    
    @property # <- применяется для гетеров   
    def numerator(self):
        return self.__numerator
    @property
    def denominator(self):
        return self.__denominator

    #----------------------------------------------------Output----------------------------------------------------

    ## overloading output
    def __str__(self):
        return '({})/({})'.format(self.__numerator, self.__denominator)

    #----------------------------------------------------Overloading of binary operators----------------------------------------------------

    ## overloading operator "+"
    def __add__(self, other):
        if isinstance(other, Fraction):
            return Fraction(
                self.__numerator * other.__denominator + self.__denominator * other.__numerator,
                self.__denominator * other.__denominator
            )
        elif isinstance(other, int):
            return Fraction(
                self.__numerator + other * self.__denominator,
                self.__denominator
            )
        else:
            raise NotImplemented

    ## overloading operator "-"
    def __sub__(self, other):
        if isinstance(other, Fraction):
            return Fraction(
                self.__numerator * other.__denominator - self.__denominator * other.__numerator,
                self.__denominator * other.__denominator
            )
        elif isinstance(other, int):
            return Fraction(
                self.__numerator - other * self.__denominator,
                self.__denominator
            )
        else:
            raise NotImplemented

    ## overloading operator "*"
    def __mul__(self, other):
        if isinstance(other, Fraction):
            return Fraction(
                self.__numerator * other.__numerator,
                self.__denominator * other.__denominator
            )
        elif isinstance(other, int):
            return Fraction(
                other * self.__numerator,
                self.__denominator
            )
        else:
            raise NotImplemented

    ## overloading operator "/"
    def __truediv__(self, other):
        if isinstance(other, Fraction):
            if other.__numerator == 0:
                raise ZeroDivisionError

            return Fraction(
                self.__numerator * other.__numerator,
                self.__denominator * other.__denominator
            )
        elif isinstance(other, int):
            if other == 0:
                raise ZeroDivisionError
            
            return Fraction(
                self.__numerator - other * self.__denominator,
                self.__denominator
            )
        else:
            raise NotImplemented
    
    ## overloading operator "**"
    def __pow__(self, other):
        if isinstance(other, int):
            return Fraction(
                self.__numerator ** other ,
                self.__denominator ** other
            )
        else:
            raise NotImplemented
    
    #----------------------------------------------------Overloading of unar operators----------------------------------------------------

    def __iadd__(self, other):
        if isinstance(other, Fraction):
            self.__numerator = self.__numerator * other.__denominator + self.__denominator * other.__numerator
            self.__denominator = self.__numerator * other.__denominator
            return self
        elif isinstance(other, int):
            self.__numerator += other * self.__denominator
            return self
        else:
            raise NotImplemented

    def __isub__(self, other):
        if isinstance(other, Fraction):
            self.__numerator = self.__numerator * other.__denominator - self.__denominator * other.__numerator
            self.__denominator = self.__numerator * other.__denominator
            return self
        elif isinstance(other, int):
            self.__numerator -= other * self.__denominator
            return self
        else:
            raise NotImplemented
    
    def __imul__(self, other):
        if isinstance(other, Fraction):
            self.__numerator *= other.__numerator
            self.__denominator *= other.__denominator
            return self
        elif isinstance(other, int):
            self.__numerator *= other
            return self
        else:
            raise NotImplemented

    def __itruediv__(self, other):
        if isinstance(other, Fraction):
            if other.__numerator == 0:
                raise ZeroDivisionError

            self.__numerator *= other.__denominator
            self.__denominator *= other.__numerator
            return self
        elif isinstance(other, int):
            if other == 0:
                raise ZeroDivisionError

            self.__denominator *= other
            return self
        else:
            raise NotImplemented

    #----------------------------------------------------Overloading of right operators----------------------------------------------------

    def __radd__(self, other):
        return Fraction(
            self.__numerator + other * self.__denominator,
            self.__denominator
        )

    def __rsub__(self, other):
        return Fraction(
            other * self.__denominator - self.__numerator,
            self.__denominator
        )
    
    def __rmul__(self, other):
        return Fraction(
            other * self.__numerator,
            self.__denominator
        )

    def __rtruediv__(self, other):
        if self.__denominator == 0:
            raise ZeroDivisionError

        return Fraction(
            other * self.__denominator,
            self.__numerator
        )   

    #----------------------------------------------------Overloading of compare operators----------------------------------------------------  

    def __eq__(self, other):
        if isinstance(other, Fraction):
            return self.__numerator * self.__denominator == self.__denominator * other.__numerator
        elif isinstance(other, int):
            return self.__numerator == self.__denominator * other
        else:
            raise NotImplemented
    
    #! не факт, что истинность == означает ложность !=
    #! поэтому перегружаем оба оператора
    def __ne__(self, other):
        if isinstance(other, Fraction):
            return self.__numerator * self.__denominator != self.__denominator * other.__numerator
        elif isinstance(other, int):
            return self.__numerator != self.__denominator * other
        else:
            raise NotImplemented
    
    def __gt__(self, other):
        if isinstance(other, Fraction):
            return self.__numerator * self.__denominator > self.__denominator * other.__numerator
        elif isinstance(other, int):
            return self.__numerator > self.__denominator * other
        else:
            raise NotImplemented
    
    def __lt__(self, other):
        return other > self
    
    def __ge__(self, other):
        return self > other or self == other
    
    def __le__(self, other):
        return other > self or self == other

    #----------------------------------------------------Some other methods for class Fraction----------------------------------------------------

    #TODO: write some other methods (goto c++ realisation)

def main():
    x = Fraction(1, 2)
    y = Fraction(3, 2)
    z = Fraction(2, 4)

    z/=0

    if (x >= z):
        print(1)
        print(x)
        print(y)
    else:
        print(2)
        print(x)
        print(y)

if __name__ == '__main__':
    main()

#??? кривая реализция проверки при делении на 0 в конструкторе и в операторе (создаю empty = N / D)
#??? перегрузил операторы типа __radd__ (когда член класса стоит справа от "+", а слагаемое слева не является членом класса), почему в питоне так дофига надо перегружать самомму