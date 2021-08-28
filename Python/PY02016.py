if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = [int(i) for i in input().split()]
        d = {i: a.count(i) for i in set(a)}
        res = dict(sorted(d.items(), key=lambda item: item[1], reverse=True))
        for i in res.items():
            if (i[1] > n / 2):
                print(i[0])
            else:
                print('NO')
            break

'''
2
9
3 3 4 2 4 4 2 4 4 0 0 0 0 0 6 6 6 6 6
'''