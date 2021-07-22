#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void count(vector<long long> a, long long n, long long k) {
    unordered_map<long long, long long> u;
    for (long long i = 0; i < n; i++)
        u[a[i]]++;
    long long tiwce_count = 0;
    for (long long i = 0; i < n; i++) {
        tiwce_count += u[k - a[i]];
        if (k - a[i] == a[i])
            tiwce_count--;
    }
    cout << tiwce_count / 2 << endl;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        long long n, k, c = 0;
        cin >> n >> k;
        vector<long long> a;
        for (long long i = 0; i < n; i++) {
            long long v;
            cin >> v;
            a.push_back(v);
        }
        count(a, n, k);
    }
    return 0;
}