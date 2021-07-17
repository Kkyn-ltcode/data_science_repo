#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dp(vector<int> a, int n) {
    vector<int> x(n, 1);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] >= a[j] && x[i] < x[j] + 1)
                x[i] = x[j] + 1;
    sort(x.begin(), x.end());
    return n - x[n - 1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << dp(a, n) << endl;
    }
    return 0;
}