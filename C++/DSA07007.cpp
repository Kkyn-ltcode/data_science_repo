#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

class infix {
   public:
    string exp1, exp2;
    map<char, int> m = {{'+', 1}, {'-', 1}, {'(', 0}};
    void function();
    void input();
    int infix_calculate(string);
    bool is_char(char);
    bool is_operator(char);
    void calculate(stack<int> &, stack<char> &);
};

void infix::calculate(stack<int> &operands, stack<char> &operators) {
    int x, y;
    if (operands.empty())
        y = 0;
    else {
        y = operands.top();
        operands.pop();
    }
    if (operands.empty())
        x = 0;
    else {
        x = operands.top();
        operands.pop();
    }
    int tmp;
    if (operators.top() == '+')
        tmp = x + y;
    if (operators.top() == '-')
        tmp = x - y;
    operands.push(tmp);
    operators.pop();
}

bool infix::is_char(char c) {
    if (c >= 'a' && c <= 'z')
        return true;
    return false;
}

bool infix::is_operator(char c) {
    if (c == '+' || c == '-')
        return true;
    return false;
}

int infix::infix_calculate(string exp) {
    stack<int> operands;
    stack<char> operators;
    for (int i = 0; i < exp.size(); i++) {
        if (is_char(exp[i]))
            operands.push(int(exp[i]));
        else if (is_operator(exp[i])) {
            while (!operators.empty() && m[operators.top()] >= m[exp[i]])
                calculate(operands, operators);
            operators.push(exp[i]);
        } else if (exp[i] == '(')
            operators.push(exp[i]);
        else if (exp[i] == ')') {
            while (!operators.empty() && operators.top() != '(')
                calculate(operands, operators);
            if (!operators.empty() && operators.top() == '(')
                operators.pop();
        }
    }
    while (!operators.empty())
        calculate(operands, operators);
    return operands.top();
}

void infix::input() {
    cin >> exp1 >> exp2;
}

void infix::function() {
    input();
    int val1 = infix_calculate(exp1);
    int val2 = infix_calculate(exp2);
    if (val1 == val2)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        infix i;
        i.function();
    }
}