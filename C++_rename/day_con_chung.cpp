#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class dp {
   public:
    int n, m, k;
    vector<int> a, b, c;
    unordered_map<int, int> a_m, b_m, c_m;
    bool printed = false;
    void function();
    void input();
    void print();
};

void dp::print() {
    vector<int> res;
    unordered_map<int, int>::iterator it = a_m.begin();
    for (it; it != a_m.end(); it++) {
        if (b_m.find(it->first) != b_m.end()) {
            if (c_m.find(it->first) != c_m.end()) {
                int tmp = min(it->second, b_m.find(it->first)->second);
                int t = min(tmp, c_m.find(it->first)->second);
                while (t--) {
                    printed = true;
                    res.push_back(it->first);
                }
            }
        }
    }
    sort(res.begin(), res.end());
    if (!printed)
        cout << "NO";
    else {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
    }
    cout << endl;
}

void dp::input() {
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    c.resize(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a_m[a[i]]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b_m[b[i]]++;
    }
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        c_m[c[i]]++;
    }
}

void dp::function() {
    input();
    print();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        dp d;
        d.function();
    }
    return 0;
}