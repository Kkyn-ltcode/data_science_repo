import string
c_i = {char: index for index, char in enumerate(string.ascii_uppercase)}
i_c = {index: char for index, char in enumerate(string.ascii_uppercase)}

def merge(a, b):
    return ''.join([i_c[(c_i[a_i] + c_i[b_i]) % 26] for (a_i, b_i) in zip(a, b)])

def rotate(s):
    step = sum([c_i[i] for i in s])
    return ''.join([i_c[(c_i[i] + step) % 26] for i in s])
    
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        print(merge(rotate(s[:len(s) // 2]), rotate(s[len(s) // 2:])))