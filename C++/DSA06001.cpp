#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        long long n;
        cin >> n;
        vector<long long> a;
        for (long long i = 0; i < n; i++) {
            int v;
            cin >> v;
            a.push_back(v);
        }
        sort(a.begin(), a.end());
        int f = 0, l = n - 1;
        while (f < l) {
            cout << a[l] << " " << a[f] << " ";
            f++;
            l--;
        }
        if (f == l)
            cout << a[f];
        cout << endl;
    }
    return 0;
}