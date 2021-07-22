#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        long long n, min = 0;
        cin >> n;
        vector<long long> a, b;
        for (long long i = 0; i < n; i++) {
            long long v;
            cin >> v;
            a.push_back(v);
        }
        for (long long i = 0; i < n; i++) {
            long long v;
            cin >> v;
            b.push_back(v);
        }
        sort(a.begin(), a.end(), greater<long long>());
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++)
            min += a[i] * b[i];
        cout << min << endl;
    }
    return 0;
}