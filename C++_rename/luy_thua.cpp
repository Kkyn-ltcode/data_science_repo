#include <iostream>
using namespace std;
#define r 1000000007

long long res(int n, int k) {
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
        int n, k;
        cin >> n >> k;
        cout << res(n, k) << endl;
    }
    return 0;
}