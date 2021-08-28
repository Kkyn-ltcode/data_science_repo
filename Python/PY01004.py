from math import sqrt
def co_prime(a, b):
    if b == 0:
        return (a == 1)
    return co_prime(b, a % b)

def check_prime(x):
    if x > 1:
        for i in range(2, int(sqrt(x)) + 1):
            if x % i == 0:
                return False
        return True
    else:
        return False

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        c = 0
        n = int(input())
        for i in range(1, n):
            if co_prime(i, n):
                c += 1
        if check_prime(c):
            print('YES')
        else:
            print('NO') 