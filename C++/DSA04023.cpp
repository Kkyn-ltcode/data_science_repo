#include <iostream>
#include <vector>
using namespace std;
#define r 1000000007

vector<vector<long long>> multiply(vector<vector<long long>> a1,
                                   vector<vector<long long>> a2, long long n, long long k) {
    vector<vector<long long>> a3(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                a3[i][j] = (a3[i][j] % r + (a1[i][k] % r) * (a2[k][j] % r)) % r;
    return a3;
}

vector<vector<long long>> divide(vector<vector<long long>> a,
                                 long long n, long long k) {
    if (k == 1)
        return a;
    vector<vector<long long>> temp = divide(a, n, k / 2);
    if (k % 2 == 0)
        return multiply(temp, temp, n, k);
    else
        return multiply(multiply(temp, temp, n, k), a, n, k);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<vector<long long>> a(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        vector<vector<long long>> result = divide(a, n, k);
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum = (sum + result[0][j]) % r;
        cout << sum << endl;
    }
    return 0;
}