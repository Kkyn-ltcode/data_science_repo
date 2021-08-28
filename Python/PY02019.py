def co_prime(a, b):
    if b == 0:
        return (a == 1)
    return co_prime(b, a % b)

if __name__ == '__main__':
    n = int(input())
    a = sorted([int(i) for i in input().split()])
    for i in range(n - 1):
        for j in range(i + 1, n):
            if co_prime(int(a[i]), int(a[j])):
                print(a[i], a[j])
