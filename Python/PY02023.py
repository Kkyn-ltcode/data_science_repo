if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        d = {i: sum(int(j) for j in str(i)) 
             for i in sorted([int(i) for i in input().split()])}
        res = dict(sorted(d.items(), key=lambda item:item[1]))
        for key, value in res.items():
            print(key, end=' ')
        print()
'''
1
9
143 43 22 99 7 9 1111 10000000 90
'''