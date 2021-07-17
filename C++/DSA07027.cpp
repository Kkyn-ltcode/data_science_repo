#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class next_greater {
   public:
    int n;
    vector<int> a;
    void function();
    void input();
    void solve();
};

void next_greater::solve() {
    stack<int> s;
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            s.push(i);
            continue;
        }
        if (a[i] <= a[s.top()])
            s.push(i);
        else {
            while (!s.empty() && a[i] > a[s.top()]) {
                res[s.top()] = a[i];
                s.pop();
            }
            s.push(i);
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
}

void next_greater::input() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void next_greater::function() {
    input();
    solve();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        next_greater r;
        r.function();
    }
}