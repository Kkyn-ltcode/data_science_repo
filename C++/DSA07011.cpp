#include <iostream>
#include <stack>
#include <string>
using namespace std;

string postfix_to_prefix(string a) {
    stack<string> s;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '/' || a[i] == '*' || a[i] == '+' || a[i] == '-') {
            string tmp1 = s.top();
            s.pop();
            string tmp2 = s.top();
            s.pop();
            string tmp = a[i] + tmp2 + tmp1;
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
        cout << postfix_to_prefix(a) << endl;
    }
    return 0;
}