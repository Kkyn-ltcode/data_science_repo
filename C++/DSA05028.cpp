#include <iostream>
#include <vector>
using namespace std;

int dp(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= m; i++)
        a[0][i] = i;
    for (int i = 0; i <= n; i++)
        a[i][0] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                a[i][j] = a[i - 1][j - 1];
            else
                a[i][j] = min(min(a[i][j - 1], a[i - 1][j]), a[i - 1][j - 1]) + 1;
        }
    }
    return a[n][m];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << dp(s1, s2) << endl;
    }
    return 0;
}