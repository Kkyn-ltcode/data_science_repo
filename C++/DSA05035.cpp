#include <iostream>
#include <vector>
using namespace std;
#define r 1000000007
#define ll long long int

class dp {
   public:
    int n;
    vector<vector<ll>> a;
    void function();
    void input();
    void solve();
    void sum(int);
};

void dp::sum(int k) {
    ll sum = 0;
    for (int i = 0; i <= 9; i++)
        sum = (sum % r + a[k][i] % r) % r;
    a[k][10] = sum;
}

void dp::solve() {
    for (int i = 0; i <= 9; i++)
        a[0][i] = 1;
    sum(0);
    for (int i = 1; i < n; i++) {
        if (i == 1)
            a[i][1] = a[i - 1][10] - 1;
        else
            a[i][1] = a[i - 1][10];
        for (int j = 2; j <= 9; j++)
            a[i][j] = a[i][j - 1] - a[i - 1][j - 1];
        sum(i);
    }
    ll res = 0;
    for (int i = 0; i < n; i++)
        res = (res % r + a[i][10] % r) % r;
    cout << res << endl;
}

void dp::input() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        a[i].resize(11, 0);
}

void dp::function() {
    input();
    solve();
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