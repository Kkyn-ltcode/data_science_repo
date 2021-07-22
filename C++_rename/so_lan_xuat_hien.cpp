#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        long long n, k;
        cin >> n >> k;
        vector<long long> a;
        unordered_map<long long, long long> u;
        for (long long i = 0; i < n; i++) {
            long long v;
            cin >> v;
            a.push_back(v);
            u[a[i]]++;
        }
        if (u[k] != 0)
            cout << u[k] << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}