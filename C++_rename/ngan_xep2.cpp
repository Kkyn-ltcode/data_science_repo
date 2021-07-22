#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        string key;
        cin >> key;
        if (key == "PUSH") {
            int value;
            cin >> value;
            s.push(value);
        } else if (key == "POP") {
            if (!s.empty())
                s.pop();
        } else {
            if (!s.empty())
                cout << s.top() << endl;
            else
                cout << "NONE" << endl;
        }
    }
    return 0;
}