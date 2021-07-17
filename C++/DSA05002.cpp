#include <iostream>
#include <vector>
using namespace std;

int dp(string s, int n) {
    vector<vector<int>> x(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == s[j - 1] && i != j)
                x[i][j] = x[i - 1][j - 1] + 1;
            else
                x[i][j] = max(x[i - 1][j], x[i][j - 1]);
        }
    }
    return x[n][n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << dp(s, n) << endl;
    }
    return 0;
}