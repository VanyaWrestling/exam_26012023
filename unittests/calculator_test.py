#!/usr/bin/env python3

# Ivan Velikanov 181-331

from unittest import TestCase, main
from calculator import calculator

class ExamVelikanTest(TestCase):
    
    #Позитивные тесты
    def test_plus(self):
        self.assertEqual(calculator("2+2"), 4)
        self.assertEqual(calculator("100+100000"), 100100)
        self.assertEqual(calculator("5000000000 + 25000000000"), 30000000000)

    def test_minus(self):
        self.assertEqual(calculator("100000-999"), 99001)
        self.assertEqual(calculator("500-1000"), -500)
    
    def test_mul(self):
        self.assertEqual(calculator("30*2"), 60)
        self.assertEqual(calculator("100*100"), 10000)
        self.assertEqual(calculator("1000000*1000000"), 1000000000000)
    
    def test_devision(self):
        self.assertEqual(calculator("2/2"), 1)
        self.assertEqual(calculator("10/0"), "Деление на 0!!!")
        self.assertNotEqual(calculator("1000/0"), 0)

    # Негативные тесты
    def test_no_signs(self):
        with self.assertRaises(ValueError) as e:
            calculator('22222')
        self.assertEqual("Необходим один знак +-/*", e.exception.args[0])
    
    def test_many_signs(self):
        with self.assertRaises(ValueError) as e:
            calculator('2+2+2')
        self.assertEqual("Выражение должно содержать 2 целых числа и 1 знак", e.exception.args[0])
    
    def test_string(self):
        with self.assertRaises(ValueError) as e:
            calculator('d;laskd;lakd;lsakd')
        self.assertEqual("Необходим один знак +-/*", e.exception.args[0])



if __name__ == "__main__":
    main()