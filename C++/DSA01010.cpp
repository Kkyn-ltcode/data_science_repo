#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int n, k, c = 0;
        cin >> n >> k;
        vector<int> a(n, 0), b(n, 0);
        for (int j = 0; j < k; j++) {
            cin >> a[j];
            b[j] = a[j];
        }
        int i = k - 1;
        while (i >= 0 && a[i] == n - k + i + 1)
            i--;
        if (a[0] == n - k + 1) {
            cout << k << endl;
            continue;
        }
        if (i >= 0) {
            a[i] += 1;
            for (int j = i + 1; j < k; j++)
                a[j] = a[i] + j - i;
        }
        for (int j = 0; j < k; j++) {
            for (int m = 0; m < k; m++) {
                if (a[j] == b[m])
                    c++;
            }
        }
        cout << k - c << endl;
    }
    return 0;
}