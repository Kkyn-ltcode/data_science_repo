#include <iostream>
#include <vector>
using namespace std;

int dp(int n) {
    if (n == 0)
        return 0;
    if (n <= 3)
        return n;
    vector<int> x(n + 1, 0);
    x[0] = 0;
    x[1] = 1;
    x[2] = 2;
    x[3] = 3;
    for (int i = 4; i <= n; i++) {
        x[i] = i;
        for (int j = 1; j * j <= i; j++)
            x[i] = min(x[i], 1 + x[i - j * j]);
    }
    return x[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp(n) << endl;
    }
    return 0;
}