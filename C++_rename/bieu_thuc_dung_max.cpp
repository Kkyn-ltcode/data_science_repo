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
    stack<char> s;
    int c = 0;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '(')
            s.push(expression[i]);
        else {
            if (!s.empty()) {
                s.pop();
                c += 2;
            }
        }
    }
    cout << c << endl;
}

void parentheses::input() {
    cin >> expression;
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