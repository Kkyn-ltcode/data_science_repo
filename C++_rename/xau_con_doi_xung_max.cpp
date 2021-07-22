#include <iostream>
#include <vector>
using namespace std;

int dp(string s) {
    int n = s.size(), res = 1;
    vector<vector<int>> x(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        x[i][i] = 1;
    for (int l = 1; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            int j = i + l;
            if (s[i] == s[j] && l == 1)
                x[i][j] = 1;
            else if (s[i] == s[j])
                x[i][j] = x[i + 1][j - 1];
            else
                x[i][j] = 0;
            if (x[i][j] == 1)
                res = max(res, l + 1);
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << dp(s) << endl;
    }
    return 0;
}