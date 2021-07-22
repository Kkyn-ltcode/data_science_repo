#include <iostream>
#include <vector>
using namespace std;

void dp(int n, int k) {
    vector<string> x(n + 1);
    x[1] = "0";
    x[2] = "1";
    for (int i = 3; i <= n; i++)
        x[i] = x[i - 2] + x[i - 1];
    cout << x[n][k - 1] << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        int n, k;
        cin >> n >> k;
        dp(n, k);
    }
    return 0;
}