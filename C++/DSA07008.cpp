#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

void infix_to_postfix(string a) {
    stack<char> s;
    unordered_map<char, int> um;
    um['^'] = 3;
    um['*'] = 2;
    um['/'] = 2;
    um['%'] = 2;
    um['+'] = 1;
    um['-'] = 1;
    um['('] = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '(')
            s.push(a[i]);
        else if (a[i] == '+' || a[i] == '-' || a[i] == '*' ||
                 a[i] == '/' || a[i] == '%' || a[i] == '^') {
            while (!s.empty() && um[s.top()] >= um[a[i]]) {
                cout << s.top();
                s.pop();
            }
            s.push(a[i]);
        } else if (a[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            if (s.top() == '(')
                s.pop();
        } else
            cout << a[i];
    }
    while (!s.empty() && s.top() != '(') {
        cout << s.top();
        s.pop();
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string a;
        cin >> a;
        infix_to_postfix(a);
        cout << endl;
    }
    return 0;
}