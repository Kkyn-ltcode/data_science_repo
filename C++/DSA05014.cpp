#include <iostream>
#include <vector>
using namespace std;

unsigned long long int dp(unsigned long long int n) {
    if (n == 0 || n == 1)
        return 1;
    unsigned long long int c[101];
    c[0] = 1;
    c[1] = 1;
    for (int i = 2; i <= n; i++) {
        c[i] = 0;
        for (int j = 0; j < i; j++)
            c[i] = c[i] + c[i - 1 - j] * c[j];
    }
    return c[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long int n;
        cin >> n;
        cout << dp(n) << endl;
    }
    return 0;
}
