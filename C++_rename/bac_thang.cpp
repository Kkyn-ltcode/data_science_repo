#include <iostream>
#include <vector>
using namespace std;
#define r 1000000007

long long dp(long long n, long long k) {
    vector<long long> f(n + 1, 0);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= k && j <= i; j++)
            f[i] = (f[i] + f[i - j]) % r;
    return f[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << dp(n, k) << endl;
    }
    return 0;
}