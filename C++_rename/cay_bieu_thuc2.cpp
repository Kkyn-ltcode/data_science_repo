#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class binary_tree {
   public:
    bool is_operator(string);
    void preorder(vector<string>);
    int to_number(string);
    void function();
};

bool binary_tree::is_operator(string c) {
    if (c == "+" || c == "-" || c == "*" || c == "/")
        return true;
    return false;
}

int binary_tree::to_number(string s) {
    int tmp = 0;
    for (int i = 0; i < s.size(); i++)
        tmp = tmp * 10 + (s[i] - '0');
    return tmp;
}

void binary_tree::preorder(vector<string> a) {
    queue<int> q;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (is_operator(a[i])) {
            int operant1 = q.front();
            q.pop();
            int operant2 = q.front();
            q.pop();
            if (a[i] == "+")
                q.push(operant2 + operant1);
            if (a[i] == "-")
                q.push(operant2 - operant1);
            if (a[i] == "*")
                q.push(operant2 * operant1);
            if (a[i] == "/")
                q.push(operant2 / operant1);
        } else
            q.push(to_number(a[i]));
    }
    cout << q.front() << endl;
}

void binary_tree::function() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    preorder(a);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        binary_tree b;
        b.function();
    }
    return 0;
}
