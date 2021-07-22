#include <algorithm>
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
        sort(a.begin(), a.end(), greater<long long>());
        for (long long i = 0; i < k; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}