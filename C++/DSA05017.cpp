#include <iostream>
#include <vector>
using namespace std;

int dp(vector<int> a, int n) {
    vector<int> x = a;
    vector<int> y = a;
    int m = 0;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] > a[j] && x[i] < x[j] + a[i])
                x[i] = x[j] + a[i];
    for (int i = n - 2; i >= 0; i--)
        for (int j = n - 1; j > i; j--)
            if (a[i] > a[j] && y[i] < y[j] + a[i])
                y[i] = y[j] + a[i];
    for (int i = 0; i < n; i++) {
        int tmp = x[i] + y[i] - a[i];
        if (m < tmp)
            m = tmp;
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