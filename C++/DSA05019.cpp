#include <iostream>
#include <vector>
using namespace std;

int dp(vector<vector<int>> a, int n, int m) {
    int mx = 0;
    vector<vector<int>> x(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0)
                x[i][j] = a[i][j];
            else if (a[i][j] != 0) {
                int min1 = min(x[i - 1][j], x[i - 1][j - 1]);
                int min2 = min(min1, x[i][j - 1]);
                x[i][j] = min2 + 1;
            }
            mx = max(mx, x[i][j]);
        }
    }
    return mx;
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