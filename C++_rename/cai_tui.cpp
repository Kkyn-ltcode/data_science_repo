#include <iostream>
#include <vector>
using namespace std;

int dp(vector<int> a, vector<int> c, int n, int v) {
    vector<vector<int>> x(n + 1, vector<int>(v + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= v; j++) {
            if (j >= a[i])
                x[i][j] = max(c[i] + x[i - 1][j - a[i]], x[i - 1][j]);
            else
                x[i][j] = x[i - 1][j];
        }
    }
    return x[n][v];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, v;
        cin >> n >> v;
        vector<int> a(n + 1, 0);
        vector<int> c(n + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        cout << dp(a, c, n, v) << endl;
    }
    return 0;
}