
#* run with: python3 tests.py -v
import unittest
import frac_class

class FractionClassTests(unittest.TestCase):

    #! each test methods start with name test_...
    def test_getters(self):
        a = frac_class.Fraction(1, 2)
        b = frac_class.Fraction(2000000000, 40000000000)
        self.assertEqual(a.numerator, 1)
        self.assertEqual(a.denominator, 2)
        self.assertEqual(b.numerator, 1)
        self.assertEqual(b.denominator, 20)
    
    def test_basic_operators(self):
        a = frac_class.Fraction(2, 3)
        b = frac_class.Fraction(3, 4)
        x = frac_class.Fraction(1, 2)
        y = frac_class.Fraction(8, 5)

        a+=1
        self.assertEqual(a, frac_class.Fraction(5, 3))
        a-=1
        self.assertEqual(a, frac_class.Fraction(2, 3))
        a*=5
        self.assertEqual(a, frac_class.Fraction(10, 3))
        b/=3
        self.assertEqual(b, frac_class.Fraction(1, 4))

        a += b
        self.assertEqual(a, frac_class.Fraction(43, 12))
        x -= b
        self.assertEqual(x, frac_class.Fraction(1, 4))
        x *= b
        self.assertEqual(x, frac_class.Fraction(1, 16))
        x /= y
        self.assertEqual(x, frac_class.Fraction(5, 16*8))

    def test_binar_operators(self):
        a = frac_class.Fraction(1, 2)
        b = frac_class.Fraction(2, 3)
        d = frac_class.Fraction(5, 3)
        c = frac_class.Fraction(9, 10)

        x = b + 3
        y = a - 1
        z = d * 3
        t = c / 9
        self.assertEqual(x, frac_class.Fraction(11, 3))
        self.assertEqual(y, frac_class.Fraction(-1, 2))
        self.assertEqual(z, frac_class.Fraction(5, 1))
        self.assertEqual(t, frac_class.Fraction(1, 10)) 

        m = y / x
        self.assertEqual(m, frac_class.Fraction(-3, 22))
        n = d + c
        self.assertEqual(n, frac_class.Fraction(77, 30))
        r = x - y
        self.assertEqual(r, frac_class.Fraction(25, 6))
        p = y * d
        self.assertEqual(p, frac_class.Fraction(-5, 6))

    def test_other_methods(self):
        a = frac_class.Fraction(1, 2)
        b = frac_class.Fraction(-5, 20)

        self.assertEqual(a.decimal(), 0.5)
        self.assertEqual(b.decimal(), -0.25)

        self.assertEqual(frac_class.Fraction().float2frac(0.125), frac_class.Fraction(1, 8))
        self.assertEqual(frac_class.Fraction().float2frac(0.3), frac_class.Fraction(3, 10))
        self.assertEqual(frac_class.Fraction().float2frac(0.203), frac_class.Fraction(203, 1000))

    def test_compare_methods(self):
        a = frac_class.Fraction(1, 2)
        b = frac_class.Fraction(1, 3)

        self.assertTrue(a != b)
        x = a / 3
        y = b / 2
        self.assertTrue(x == y)
        self.assertTrue(a > b)
        x = a - 1
        self.assertTrue(x < b)
        self.assertTrue(a >= a)
        self.assertTrue(b <= b)



if __name__ == '__main__':
    unittest.main()