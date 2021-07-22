#include <iostream>
#include <stack>
#include <string>
using namespace std;

string postfix_to_infix(string a) {
    stack<string> s;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '/' || a[i] == '*' || a[i] == '+' || a[i] == '-') {
            string tmp1 = s.top();
            s.pop();
            string tmp2 = s.top();
            s.pop();
            string tmp = "(" + tmp2 + a[i] + tmp1 + ")";
            s.push(tmp);
        } else
            s.push(string(1, a[i]));
    }
    return s.top();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << postfix_to_infix(a) << endl;
    }
    return 0;
}