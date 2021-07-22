n = int(input())
a = input()
a = a.split()

def selection_sort(a, i):
    j = i + 1
    min = i
    while j < n:
        if a[min] > a[j]:
            min = j
        j += 1
    a[i], a[min] = a[min], a[i]
    print('Buoc %s: ' %(i + 1), end = '')
    for k in range(n):
        print(a[k], end = ' ')
    print()

for i in range(n - 1):
    selection_sort(a, i)