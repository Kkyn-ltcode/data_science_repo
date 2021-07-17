#include <iostream>
#include <stack>
#include <string>
using namespace std;

int check(string a) {
    int c = 0;
    stack<char> s;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '(')
            s.push(a[i]);
        else {
            if (s.empty()) {
                c += 1;
                s.push('(');
            } else
                s.pop();
        }
    }
    c = c + s.size() / 2;
    return c;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        string a;
        cin >> a;
        cout << check(a) << endl;
    }
    return 0;
}