#include <iostream>
#include <vector>
using namespace std;

long long dp(string s) {
    vector<long long> x(s.size(), 0);
    x[0] = s[0] - '0';
    long long res = x[0];
    for (int i = 1; i < s.size(); i++) {
        x[i] = (i + 1) * (s[i] - '0') + 10 * x[i - 1];
        res += x[i];
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