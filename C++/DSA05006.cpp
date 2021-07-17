#include <iostream>
#include <vector>
using namespace std;

int dp(vector<int> a, int n) {
    int m = a[0];
    vector<int> x = a;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && x[i] < x[j] + a[i]) {
                x[i] = x[j] + a[i];
                m = max(m, x[i]);
            }
        }
    }
    return m;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << dp(a, n) << endl;
    }
    return 0;
}