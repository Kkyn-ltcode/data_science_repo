#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

class infix {
   public:
    string expression;
    map<char, long> m = {{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}, {'(', 0}};
    stack<long> operands;
    stack<char> operators;
    void function();
    void input();
    void infix_calculate();
    bool is_operand(char);
    bool is_operator(char);
    void calculate();
};

void infix::calculate() {
    long y = operands.top();
    operands.pop();
    long x = operands.top();
    operands.pop();
    long tmp;
    if (operators.top() == '+')
        tmp = x + y;
    if (operators.top() == '-')
        tmp = x - y;
    if (operators.top() == '*')
        tmp = x * y;
    if (operators.top() == '/')
        tmp = x / y;
    operands.push(tmp);
    operators.pop();
}

bool infix::is_operand(char c) {
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

bool infix::is_operator(char c) {
    if (c == '*' || c == '/' || c == '+' || c == '-')
        return true;
    return false;
}

void infix::infix_calculate() {
    for (long i = 0; i < expression.size(); i++) {
        if (is_operand(expression[i])) {
            long num = 0;
            while (is_operand(expression[i])) {
                num = num * 10 + expression[i] - '0';
                i++;
            }
            i--;
            operands.push(num);
        } else if (is_operator(expression[i])) {
            while (!operators.empty() && m[operators.top()] >= m[expression[i]])
                calculate();
            operators.push(expression[i]);
        } else if (expression[i] == '(')
            operators.push(expression[i]);
        else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(')
                calculate();
            if (!operators.empty() && operators.top() == '(')
                operators.pop();
        }
    }
    while (!operators.empty())
        calculate();
    cout << operands.top() << endl;
}

void infix::input() {
    cin >> expression;
}

void infix::function() {
    input();
    infix_calculate();
}

int main() {
    long test_case;
    cin >> test_case;
    while (test_case--) {
        infix i;
        i.function();
    }
}