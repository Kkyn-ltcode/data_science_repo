#include <iostream>
using namespace std;

struct Stack {
    int top;
    int a[200];
};

int main() {
    string key;
    Stack s;
    s.top = -1;
    while (true) {
        cin >> key;
        if (key == "push") {
            s.top += 1;
            int value;
            cin >> value;
            s.a[s.top] = value;
        } else if (key == "pop") {
            if (s.top != -1)
                s.top -= 1;
            if (s.top == -1) {
                cout << "empty" << endl;
                break;
            }
        } else {
            if (s.top == -1) {
                cout << "empty" << endl;
                break;
            } else {
                for (int i = 0; i <= s.top; i++)
                    cout << s.a[i] << " ";
                cout << endl;
            }
        }
    }
    return 0;
}