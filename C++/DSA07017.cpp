#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

void next_greater(vector<int> a, int n,
                  unordered_map<int, int> &NG, string order) {
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++) {
        if (s.empty()) {
            s.push(i);
            continue;
        }
        while (!s.empty() && ((order == "G") ? a[i] > a[s.top()] : a[i] < a[s.top()])) {
            NG[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        NG[s.top()] = -1;
        s.pop();
    }
}

void next_smaller_greater(vector<int> a, int n) {
    unordered_map<int, int> NG;
    unordered_map<int, int> NS;
    next_greater(a, n, NG, "G");
    next_greater(a, n, NS, "S");
    for (int i = 0; i < n; i++) {
        if (NG[i] != -1 && NS[NG[i]] != -1)
            cout << a[NS[NG[i]]] << " ";
        else
            cout << -1 << " ";
    }
    cout << endl;
}

void init() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    next_smaller_greater(a, n);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
    }
    return 0;
}