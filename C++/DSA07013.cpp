#include <iostream>
#include <stack>
#include <string>
using namespace std;

void postfix(string a) {
    stack<int> s;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
            int s1 = s.top();
            s.pop();
            int s2 = s.top();
            s.pop();
            int tmp;
            if (a[i] == '+')
                tmp = s2 + s1;
            else if (a[i] == '-')
                tmp = s2 - s1;
            else if (a[i] == '/')
                tmp = s2 / s1;
            else
                tmp = s2 * s1;
            s.push(tmp);
        } else
            s.push(a[i] - '0');
    }
    cout << s.top() << endl;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        string a;
        cin >> a;
        postfix(a);
    }
    return 0;
}