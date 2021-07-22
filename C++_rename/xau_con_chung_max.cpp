#include <iostream>
#include <vector>
using namespace std;

int dp(string a, string b, int m, int n) {
    vector<vector<int>> x(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                x[i][j] = x[i - 1][j - 1] + 1;
            else
                x[i][j] = max(x[i - 1][j], x[i][j - 1]);
        }
    }
    return x[m][n];
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        string a, b;
        cin >> a >> b;
        int m = a.size(), n = b.size();
        cout << dp(a, b, m, n) << endl;
    }
    return 0;
}