if __name__ == '__main__':
    a = []
    while (len(a) != 10):
        a += input().split()
    a = set([int(i) % 42 for i in a])
    print(len(a))
'''
42 84 252 420 840
126 42 84 420 126

39 40 41 42 43 44 82
83 84 85
'''     