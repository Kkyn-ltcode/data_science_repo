#include <iostream>
#include <stack>
#include <string>
using namespace std;

void prefix(string a) {
    stack<int> s;
    for (int i = a.size(); i >= 0; i--) {
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
            int s1 = s.top();
            s.pop();
            int s2 = s.top();
            s.pop();
            int tmp;
            if (a[i] == '+')
                tmp = s1 + s2;
            else if (a[i] == '-')
                tmp = s1 - s2;
            else if (a[i] == '/')
                tmp = s1 / s2;
            else
                tmp = s1 * s2;
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
        prefix(a);
    }
    return 0;
}