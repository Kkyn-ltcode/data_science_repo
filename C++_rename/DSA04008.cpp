#include <iostream>
#include <vector>
using namespace std;
#define r 1000000007

long long nth_fibonacci() {
    int n;
    cin >> n;
    vector<long long> f(n + 1, 0);
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = (f[i - 1] % r + f[i - 2] % r) % r;
    return f[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << nth_fibonacci() << endl;
    }
    return 0;
}