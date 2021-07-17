#include <iostream>
using namespace std;
#define r 123456789

long long res(int n, long long k) {
    if (k == 1)
        return n;
    long long x = res(n, k / 2);
    if (k % 2 == 0)
        return x * x % r;
    else
        return n * (x * x % r) % r;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        long long n;
        cin >> n;
        cout << res(2, n - 1) << endl;
    }
    return 0;
}