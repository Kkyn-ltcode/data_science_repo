#include <iostream>
using namespace std;
#define r 1000000007

long long res(long long n, long long k) {
    if (k == 0)
        return 1;
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
        long long n, k = 0;
        cin >> n;
        long long s = n;
        while (s) {
            k = k * 10 + s % 10;
            s /= 10;
        }
        cout << res(n, k) << endl;
    }
    return 0;
}