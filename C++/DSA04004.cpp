#include <iostream>
using namespace std;

long long divide(long long n, long long left, long long right, long long k) {
    if (left == right)
        return 1;
    long long mid = (left + right) / 2;
    if (mid == k)
        return n;
    if (k < mid)
        return divide(n - 1, left, mid - 1, k);
    return divide(n - 1, mid + 1, right, k);
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        long long n, k;
        cin >> n >> k;
        long long len = 1;
        for (long long i = 0; i < n - 1; i++)
            len = len * 2 + 1;
        cout << divide(n, 1, len, k) << endl;
    }
    return 0;
}