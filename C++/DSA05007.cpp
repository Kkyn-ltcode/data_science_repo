#include <iostream>
#include <vector>
using namespace std;

int dp(vector<int> a, int n) {
    vector<int> x = a;
    x[1] = max(a[0], a[1]);
    for (int i = 2; i < n; i++)
        x[i] = max(x[i - 2] + a[i], x[i - 1]);
    return x[n - 1];
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