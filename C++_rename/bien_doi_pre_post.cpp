#include <iostream>
#include <stack>
#include <string>
using namespace std;

string prefix(string a) {
    stack<string> s;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
            string s1 = s.top();
            s.pop();
            string s2 = s.top();
            s.pop();
            string temp = s1 + s2 + a[i];
            s.push(temp);
        } else
            s.push(string(1, a[i]));
    }
    return s.top();
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        string a;
        cin >> a;
        cout << prefix(a) << endl;
    }
    return 0;
}