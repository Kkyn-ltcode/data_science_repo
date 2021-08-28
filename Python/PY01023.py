def primeExtract(n):
    c = 0
    while (n % 2 == 0):
        n /= 2
        c += 1
    if (c != 0):
        print(f'* 2^{c} ', end='')
    c = 0
    k = 3
    while (n != 1):
        while (n % k == 0):
            n /= k
            c += 1
        if (c != 0):
            print(f'* {k}^{c} ', end='')
        c = 0
        k += 2

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        print(f'1 ', end='')
        primeExtract(n)
        print()