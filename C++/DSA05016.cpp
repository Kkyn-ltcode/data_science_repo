#include <iostream>
#include <vector>
using namespace std;

int dp(int n) {
    vector<int> ugly(n + 1, 1);
    int i2 = 0, i3 = 0, i5 = 0;
    int n2 = 2, n3 = 3, n5 = 5, res = 1;
    for (int i = 1; i < n; i++) {
        res = min(min(n2, n3), n5);
        ugly[i] = res;
        if (res == n2) {
            i2++;
            n2 = ugly[i2] * 2;
        }
        if (res == n3) {
            i3++;
            n3 = ugly[i3] * 3;
        }
        if (res == n5) {
            i5++;
            n5 = ugly[i5] * 5;
        }
    }
    return res;
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