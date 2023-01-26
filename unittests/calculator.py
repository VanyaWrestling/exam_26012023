#!/usr/bin/env python3

# Ivan Velikanov 181-331

def calculator(expression):
    allowed = "+-/*"
    if not any(sign in expression for sign in allowed):
        raise ValueError(f'Необходим один знак {allowed}')
    for sign in allowed:
        if sign in expression:
            try:
                left, right = expression.split(sign)
                left, right = int(left), int(right)
                if sign == "+":
                    return left + right
                if sign == "-":
                    return left - right
                if sign == "*":
                    return left * right
                if sign == "/":
                    try:
                        return int(left / right)
                    except ZeroDivisionError:
                        return "Деление на 0!!!"
            except (ValueError, TypeError):
                raise ValueError("Выражение должно содержать 2 целых числа и 1 знак")

if __name__ == "__main__":
    print(calculator("2222"))

