#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class solution {
   public:
    int n;
    vector<int> a;
    void function();
    void input();
    void solve();
};

void solution::solve() {
    int tmp1 = a[0] * a[1];
    int tmp2 = a[n - 1] * a[n - 2];
    int tmp3 = a[n - 1] * a[n - 2] * a[n - 3];
    int tmp4 = a[0] * a[1] * a[n - 1];
    int max1 = max(tmp1, tmp2);
    int max2 = max(tmp3, tmp4);
    cout << max(max1, max2) << endl;
}

void solution::input() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
}

void solution::function() {
    input();
    solve();
}

int main() {
    solution s;
    s.function();
}