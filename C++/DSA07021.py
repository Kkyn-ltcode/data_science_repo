n = int(input())

def correct_parentheses(s):
    st = []
    st.append(-1)
    m = 0
    for i in range(len(s)):
        if s[i] == '(':
            st.append(i)
        else:
            st.pop()
            if len(st) != 0:
                m = max(m, i - st[-1])
            else:
                st.append(i)
    return m

for i in range(n):
    s = input()
    print(correct_parentheses(s))