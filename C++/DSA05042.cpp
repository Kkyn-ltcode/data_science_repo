#include <iostream>
#include <unordered_map>
#include <vector>
#define ll long long int
using namespace std;

class dp {
   public:
    ll n, k;
    vector<ll> a;
    void function();
    void input();
    bool solve();
};

bool dp::solve() {
    unordered_map<ll, ll> um;
    ll cur_sum = 0;
    for (int i = 0; i < n; i++) {
        cur_sum += a[i];
        if (cur_sum == k)
            return true;
        if (um.find(cur_sum - k) != um.end())
            return true;
        um[cur_sum] += 1;
    }
    return false;
}

void dp::input() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void dp::function() {
    input();
    if (solve())
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
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