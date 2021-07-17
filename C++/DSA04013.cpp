#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int kanguru() {
    int n, num = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int mid = n / 2 + n % 2 - 1;
    int i = mid;
    int j = n - 1;
    while (i >= 0) {
        if (a[j] >= 2 * a[i]) {
            num++;
            i--;
            j--;
        } else
            i--;
    }
    return num + n - 2 * num;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        cout << kanguru() << endl;
    }
    return 0;
}
