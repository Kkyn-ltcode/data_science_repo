n = int(input())
a = input()
a = a.split()

def sort(a, i, j):
    while j < n:
        if a[i] > a[j]:
            a[i], a[j] = a[j], a[i]
        j += 1
    print('Buoc %s: ' %(i + 1), end = '')
    for k in range(n):
        print(a[k], end = ' ')
    print()

for i in range(n - 1):
    sort(a, i, i + 1)