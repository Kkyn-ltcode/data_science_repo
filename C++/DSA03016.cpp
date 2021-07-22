#include <iostream>
#include <vector>
using namespace std;

void greedy(int s, int m) {
    if (s == 0) {
        if (m == 1)
            cout << 0;
        else
            cout << -1;
        return;
    }
    if (s > 9 * m) {
        cout << -1;
        return;
    }
    vector<int> a(m, 0);
    s -= 1;
    for (int i = m - 1; i > 0; i--) {
        if (s > 9) {
            a[i] = 9;
            s -= 9;
        } else {
            a[i] = s;
            s = 0;
        }
    }
    a[0] = s + 1;
    for (int i = 0; i < m; i++)
        cout << a[i];
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int s, m;
        cin >> s >> m;
        greedy(s, m);
        cout << endl;
    }
    return 0;
}