#include <iostream>
#include <vector>
using namespace std;

int dp(vector<vector<int>> a, int n, int m) {
    vector<vector<int>> x(n, vector<int>(m, 0));
    x[0][0] = a[0][0];
    for (int i = 1; i < n; i++)
        x[i][0] = x[i - 1][0] + a[i][0];
    for (int j = 1; j < m; j++)
        x[0][j] = x[0][j - 1] + a[0][j];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int min1 = min(x[i - 1][j], x[i - 1][j - 1]);
            int min2 = min(min1, x[i][j - 1]);
            x[i][j] = min2 + a[i][j];
        }
    }
    return x[n - 1][m - 1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        cout << dp(a, n, m) << endl;
    }
    return 0;
}