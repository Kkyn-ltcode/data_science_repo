#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class dp {
   public:
    long long int n, m, k;
    vector<long long int> a, b, c;
    unordered_map<long long int, long long int> a_m, b_m, c_m;
    bool printed = false;
    void function();
    void input();
    void print();
};

void dp::print() {
    vector<long long int> res;
    unordered_map<long long int, long long int>::iterator it = a_m.begin();
    for (it; it != a_m.end(); it++) {
        if (b_m.find(it->first) != b_m.end()) {
            if (c_m.find(it->first) != c_m.end()) {
                printed = true;
                res.push_back(it->first);
            }
        }
    }
    sort(res.begin(), res.end());
    if (!printed)
        cout << -1;
    else {
        for (long long int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
    }
    cout << endl;
}

void dp::input() {
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    c.resize(k);
    for (long long int i = 0; i < n; i++) {
        cin >> a[i];
        a_m[a[i]]++;
    }
    for (long long int i = 0; i < m; i++) {
        cin >> b[i];
        b_m[b[i]]++;
    }
    for (long long int i = 0; i < k; i++) {
        cin >> c[i];
        c_m[c[i]]++;
    }
}

void dp::function() {
    input();
    print();
}

int main() {
    long long int test_case;
    cin >> test_case;
    while (test_case--) {
        dp d;
        d.function();
    }
    return 0;
}