#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool check(string a) {
    stack<char> s;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != ')')
            s.push(a[i]);
        else {
            bool has = false;
            while (s.top() != '(') {
                if (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')
                    has = true;
                s.pop();
            }
            s.pop();
            if (!has)
                return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        string a = "";
        while (a == "")
            getline(cin, a);
        if (check(a))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}