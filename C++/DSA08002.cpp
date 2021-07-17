#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    queue<int> q;
    for (int x = 0; x < t; x++) {
        string s;
        cin >> s;
        if (s == "PUSH") {
            int n;
            cin >> n;
            q.push(n);
        } else if (s == "POP") {
            if (!q.empty())
                q.pop();
        } else {
            if (!q.empty())
                cout << q.front() << endl;
            else
                cout << "NONE" << endl;
        }
    }
    return 0;
}