#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class sorting {
   public:
    int n;
    vector<int> a;
    void input();
    void solve();
};

void sorting::solve() {
    int ans = 0;
    map<int, int> m;
    vector<int> tmp = a;
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++)
        m[a[i]] = i;
    for (int i = 0; i < n; i++) {
        if (a[i] != tmp[i]) {
            ans++;
            int x = a[i];
            swap(a[i], a[m[tmp[i]]]);
            m[x] = m[tmp[i]];
			m[tmp[i]] = i;
        }
    }
    cout << ans << endl;
}

void sorting::input() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        sorting s;
        s.input();
        s.solve();
    }
}