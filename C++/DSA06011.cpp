#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void sorting() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int min_sum = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            if (abs(sum) < abs(min_sum))
                min_sum = sum;
        }
    }
    cout << min_sum << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        sorting();
    return 0;
}