n = int(input())
a = input()
a = a.split()

def insertion_sort(a, i):
    for j in range(i):
        if a[i] < a[j]:
            a[i], a[j] = a[j], a[i]
    print('Buoc %s: ' %(i), end = '')
    for k in range(i + 1):
        print(a[k], end = ' ')
    print()

for i in range(n):
    insertion_sort(a, i)