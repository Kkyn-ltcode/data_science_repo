#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class next_greater {
   public:
    string sentence;
    void function();
    void input();
    void reverse_word();
};

void next_greater::reverse_word() {
    stack<char> s;
    for (int i = sentence.size() - 1; i >= 0; i--) {
        if (sentence[i] == ' ') {
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }
            cout << " ";
        } else
            s.push(sentence[i]);
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

void next_greater::input() {
    getline(cin, sentence);
}

void next_greater::function() {
    input();
    reverse_word();
}

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {
        next_greater r;
        r.function();
    }
}