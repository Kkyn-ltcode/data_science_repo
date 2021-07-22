import atexit
import sys
import io

def sum(k, a):
    sum = 0
    for i in range(10):
        sum = sum + a[k][i]
    return sum

def solve(a, n):
    for i in range(10):
        a[0][i] = 1
    a[0][10] = sum(0, a)
    for i in range(1, n):
        if i == 1:
            a[i][1] = a[i - 1][10] - 1
        else:
            a[i][1] = a[i - 1][10]
        for j in range(2, 10):
            a[i][j] = a[i][j - 1] - a[i - 1][j - 1]
        a[i][10] = sum(i, a)
    res = 0
    for i in range(n):
        res = res + a[i][10]
    print(res % 1000000007)

def inp():
    n = int(input())
    a = [[0 for j in range(11)] for i in range(n)]
    solve(a, n)

if __name__ == '__main__':
    test_case = int(input())
    for i in range(test_case):
        inp()