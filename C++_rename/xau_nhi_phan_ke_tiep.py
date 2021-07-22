def bit(s, j):
    if j >= 0:
        if s[j] == '0':
            s[j] = '1'
        else:
            s[j] = '0'
            bit(s, j - 1)
    return ''.join(s)

n = int(input())
for i in range(n):
    s = []
    x = input()
    for i in x:
        s.append(i)
    j = len(x) - 1
    print(bit(s, j))