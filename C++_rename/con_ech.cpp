#include <iostream>
#include <vector>
using namespace std;

long long dp(long long n) {
    vector<long long> f(n + 1, 0);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= 3 && i >= j; j++)
            f[i] += f[i - j];
    return f[n];
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