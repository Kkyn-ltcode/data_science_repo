#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class dp {
   public:
    int n;
    vector<int> a;
    void function();
    void input();
    int find_longest_subarray();
};

int dp::find_longest_subarray() {
    vector<int> x(n, 1);
    vector<int> y(n, 1);
    vector<int> b = a;
    reverse(b.begin(), b.end());
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1])
            x[i] = x[i - 1] + 1;
        if (b[i] > b[i - 1])
            y[i] = y[i - 1] + 1;
    }
    for (int i = 0; i < n; i++)
        x[i] = x[i] + y[n - i - 1];
    sort(x.begin(), x.end());
    return x[n - 1] - 1;
}

void dp::input() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void dp::function() {
    input();
    cout << find_longest_subarray() << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        dp d;
        d.function();
    }
}