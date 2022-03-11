#! /usr/bin/env python3

class Fraction:
    __slots__ = ['__numerator', '__denominator']

    ## Constructor
    def __init__(self, N = 1, D = 1):
        self.__numerator = N
        self.__denominator = D
        print('Constructor called for', '[' + str(hex(id(self))) + ']')
    ## Distructor
    def __del__(self):
        print('Destrictor called for', '[' + str(hex(id(self))) + ']')

    @property # <- применяется для гетеров   
    def numerator(self):
        return self.__numerator
    @property
    def denominator(self):
        return self.__denominator


def main():
    print('hello, world!')
    a = Fraction(1, 2)
    print(a.numerator)
    print(a.denominator)

if __name__ == '__main__':
    main()