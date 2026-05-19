#!/usr/bin/python3
import sys

def fizzbuzz(n):
    """
    FizzBuzz function prints numbers from 1 to n separated by a space.
    """
    if n < 1:
        return

    tmp_list = []
    for i in range(1, n + 1):
        # 1. Check the combined condition FIRST
        if i % 3 == 0 and i % 5 == 0:
            tmp_list.append("FizzBuzz")
        # 2. Check individual conditions next
        elif i % 3 == 0:
            tmp_list.append("Fizz")
        elif i % 5 == 0:
            tmp_list.append("Buzz")
        else:
            tmp_list.append(str(i))
            
    print(" ".join(tmp_list))

if __name__ == '__main__':
    if len(sys.argv) <= 1:
        print("Missing argument")
        sys.exit(1)

    number = int(sys.argv[1])
    fizzbuzz(number)
