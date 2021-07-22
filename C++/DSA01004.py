def next_gen(i):
    j = x[i - 1] + 1
    while j <= (n - k + i):
        x[i] = j
        if i == k:
            y = 1
            while y <= k:
                print(x[y], end = '')
                y += 1
            print(end = ' ')
        else:
            next_gen(i + 1)
        j += 1

t = int(input())
for i in range(t):
    a = input()
    a = a.split()
    n = int(a[0])
    k = int(a[1])
    x = []
    for i in range(n + 1):
        x.append(' ')
    x[0] = 0
    next_gen(1)
    print()