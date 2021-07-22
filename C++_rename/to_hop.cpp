#include <iostream>
#include <vector>
using namespace std;
#define r 1000000007

int dp(int n, int k) {
    vector<vector<int>> c(n + 1, vector<int>(k + 1, 1));
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= k; j++)
            if (i != j)
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % r;
    return c[n][k];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << dp(n, k) << endl;
    }
    return 0;
}