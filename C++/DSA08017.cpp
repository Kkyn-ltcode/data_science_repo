#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void res(int n) {
    string s = "";
    queue<string> q;
    stack<string> st;
    q.push("6");
    q.push("8");
    while (q.front().size() <= n) {
        s = q.front();
        q.pop();
        st.push(s);
        string s1 = s + '6';
        string s2 = s + '8';
        q.push(s1);
        q.push(s2);
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int n;
        cin >> n;
        res(n);
        cout << endl;
    }
    return 0;
}