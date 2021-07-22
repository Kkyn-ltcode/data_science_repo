#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        long long n, k;
        cin >> n >> k;
        vector<long long> a;
        for (long long i = 0; i < n; i++) {
            long long v;
            cin >> v;
            a.push_back(v);
        }
        for (long long i = 1; i < n; i++) {
            long long dif = abs(a[i] - k);
            long long j = i - 1;
            if (abs(a[j] - k) > dif) {
                long long tmp = a[i];
                while (j >= 0 && abs(a[j] - k) > dif) {
                    a[j + 1] = a[j];
                    j--;
                }
                a[j + 1] = tmp;
            }
        }
        for (long long i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}