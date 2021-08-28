from math import sqrt
def check_prime(x):
    if x > 1:
        for i in range(2, int(sqrt(x)) + 1):
            if x % i == 0:
                return False
        return True
    else:
        return False
    
if __name__ == '__main__':
    n = int(input())
    a = input().split() 
    b = {i: 0 for i in set(a)}
    for i in range(n):
        if check_prime(int(a[i])) and b[a[i]] == 0:
            print(a[i], a.count(a[i]))
            b[a[i]] = 1