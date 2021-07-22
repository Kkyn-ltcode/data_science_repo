n = int(input())
a = input()
a = a.split()

def bubble_sort(a, i):
    j = 1
    sorted = True
    while j < n:
        if a[j] < a[j - 1]:
            sorted = False
            a[j - 1], a[j] = a[j], a[j - 1]
        j += 1
    if sorted == True:
        return 1
    else:
        print('Buoc %s: ' %(i + 1), end = '')
        for k in range(n):
            print(a[k], end = ' ')
        print()

i = 0
while True:
    loop = bubble_sort(a, i)
    if loop == 1:
        break
    i += 1