#include <iostream>
#include <vector>
using namespace std;

bool can_partition(vector<int> a, vector<int> subset_sum, vector<bool> used,
                   int sub_sum, int k, int n, int subset_index, int index) {
    if (subset_sum[subset_index] == sub_sum) {
        if (subset_index == k - 2)
            return true;
        else
            return can_partition(a, subset_sum, used, sub_sum,
                                 k, n, subset_index + 1, n - 1);
    }
    for (int i = index; i >= 0; i--) {
        if (!used[i]) {
            int tmp = subset_sum[subset_index] + a[i];
            if (tmp <= sub_sum) {
                used[i] = true;
                subset_sum[subset_index] += a[i];
                bool possible = can_partition(a, subset_sum, used,
                                              sub_sum, k, n, subset_index, i - 1);
                used[i] = false;
                subset_sum[subset_index] -= a[i];
                if (possible)
                    return true;
            }
        }
    }
    return false;
}

bool divide_solution() {
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> a(n, 0);
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (k > n)
        return false;
    if (k == 1)
        return true;
    if (sum % k != 0)
        return false;
    int sub_sum = sum / k;
    vector<int> subset_sum(k, 0);
    return can_partition(a, subset_sum, used, sub_sum,
                         k, n, 0, n - 1);
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        if (divide_solution())
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}
