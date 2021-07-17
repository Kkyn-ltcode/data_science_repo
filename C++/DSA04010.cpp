#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void max(vector<int> a, int n) {
    int m1 = INT_MIN, m2 = 0;
    for (int i = 0; i < n; i++) {
        m2 += a[i];
        if (m1 < m2)
            m1 = m2;
        if (m2 < 0)
            m2 = 0;
    }
    cout << m1 << endl;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        max(a, n);
    }
    return 0;
}