from math import sqrt
def max_gcd(a, b):
    if (b == 0):
        return a
    return max_gcd(b, a % b)

def isPrime(x):
    if (x > 1):
        for i in range(2, int(sqrt(x)) + 1):
            if (x % i == 0):
                return False
        return True
    else:
        return False

def maxPrime(a, b):
    n = max_gcd(a, b)
    x = 0
    for i in str(n):
        x += int(i)
    return isPrime(x)

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().split()
        a, b = int(s[0]), int(s[1])
        if (maxPrime(a, b)):
            print('YES')
        else:
            print('NO')

