#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class parentheses {
   public:
    string expression;
    void function();
    void input();
    void count();
};

void parentheses::count() {
    stack<int> s;
    int c = 0;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '(') {
            s.push(++c);
            cout << c << " ";
        } else if (expression[i] == ')') {
            cout << s.top() << " ";
            s.pop();
        }
    }
    cout << endl;
}

void parentheses::input() {
    getline(cin, expression);
}

void parentheses::function() {
    input();
    count();
}

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {
        parentheses r;
        r.function();
    }
}