#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        long long n, key = -1;
        cin >> n;
        vector<long long> a, b;
        for (long long i = 0; i < n; i++) {
            long long v;
            cin >> v;
            a.push_back(v);
        }
        for (long long i = 0; i < n - 1; i++) {
            long long v;
            cin >> v;
            if (a[i] != v && key == -1)
                key = i;
            else
                b.push_back(v);
        }
        if (key == -1)
            cout << n << endl;
        else
            cout << key + 1 << endl;
    }
    return 0;
}