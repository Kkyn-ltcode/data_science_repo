#include <iostream>
#include <vector>
using namespace std;

bool dp(vector<int> a, int n, int s) {
    vector<vector<bool>> x(n + 1, vector<bool>(s + 1, false));
    x[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j < a[i])
                x[i][j] = x[i - 1][j];
            else {
                if (!x[i - 1][j])
                    x[i][j] = x[i - 1][j - a[i]];
                else
                    x[i][j] = x[i - 1][j];
            }
        }
    }
    return x[n][s];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (dp(a, n, s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}