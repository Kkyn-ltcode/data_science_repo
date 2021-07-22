#include <iostream>
#include <queue>
using namespace std;

void res(int n) {
    string s = "";
    queue<string> q, q1;
    q.push("6");
    q.push("8");
    while (q.front().size() <= n) {
        s = q.front();
        q.pop();
        q1.push(s);
        string s1 = s + "6";
        string s2 = s + "8";
        q.push(s1);
        q.push(s2);
    }
    cout << q1.size() << endl;
    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int n;
        cin >> n;
        res(n);
    }
    return 0;
}