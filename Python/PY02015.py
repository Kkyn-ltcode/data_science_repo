if __name__ == '__main__':
    while (True):
        a = [int(i) for i in input().split()]
        if (a.count(0) == len(a)):
            break
        c = 0
        while (a.count(a[0]) != len(a)):
            c += 1
            tmp = a[0]
            for i in range(len(a)):
                if (i == len(a) - 1):
                    a[i] = abs(a[i] - tmp)
                else:
                    a[i] = abs(a[i] - a[i + 1])
        print(c)