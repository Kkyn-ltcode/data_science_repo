#include <iostream>
#include <set>
#include <vector>
using namespace std;

void Intersection(set<long long> a, set<long long> b) {
    set<long long>::iterator it;
    for (it = a.begin(); it != a.end(); it++)
        if (b.find(*it) != b.end())
            cout << *it << " ";
    cout << endl;
}

void Union(set<long long> u, long long n, long long m) {
    set<long long> a, b;
    for (long long i = 0; i < n; i++) {
        long long v;
        cin >> v;
        a.insert(v);
        u.insert(v);
    }
    for (long long i = 0; i < m; i++) {
        long long v;
        cin >> v;
        u.insert(v);
        b.insert(v);
    }
    set<long long>::iterator it;
    for (it = u.begin(); it != u.end(); it++)
        cout << *it << " ";
    cout << endl;
    Intersection(a, b);
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        long long n, m;
        cin >> n >> m;
        set<long long> u;
        Union(u, n, m);
    }
    return 0;
}