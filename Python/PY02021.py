def findCommon(a, n):
    i, j, k = 0, 0, 0
    res = []
    while (i < n[0] and j < n[1] and k < n[2]):
        if (a[0][i] == a[1][j] and a[1][j] == a[2][k]):
            res.append(a[0][i])
            i += 1
            j += 1 
            k += 1
        elif a[0][i] < a[1][j]:
            i += 1
        elif a[1][j] < a[2][k]:
            j += 1
        else:
            k += 1
    if (len(res) != 0):
        for i in res:
            print(i, end=' ')
    else:
        print('NO', end='')
    print()

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = [int(i) for i in input().split()]
        a = [[int(i) for i in input().split()] for i in range(3)]
        findCommon(a, n)
'''
3
6 5 8
1 5 10 20 40 80
5 7 20 80 100
3 4 15 20 30 70 80 120

3 5 4
1 5 5
3 4 5 5 10
5 5 10 20

3 3 3
1 2 3
4 5 6
7 8 9
'''