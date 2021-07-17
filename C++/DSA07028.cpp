#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class stock {
   public:
    int n;
    vector<int> a;
    void function();
    void input();
    void solve();
};

void stock::solve() {
    stack<int> s;
    vector<int> res(n, 1);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            s.push(i);
            continue;
        }
        if (a[i] >= a[s.top()]) {
            while (!s.empty() && a[i] >= a[s.top()]) {
                res[i] += res[s.top()];
                s.pop();
            }
            s.push(i);
        } else
            s.push(i);
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
}

void stock::input() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void stock::function() {
    input();
    solve();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        stock r;
        r.function();
    }
}