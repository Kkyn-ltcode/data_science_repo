#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int m = 0; m < t; m++) {
        int n;
        cin >> n;
        vector<int> a;
        a.push_back(0);
        for (int i = 1; i <= n; i++) {
            int v;
            cin >> v;
            a.push_back(v);
        }
        if (a[1] == n && a[n] == 1) {
            sort(a.begin(), a.end());
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << endl;
            continue;
        }
        int j = n - 1;
        while (j > 0 && a[j] > a[j + 1])
            j--;
        if (j > 0) {
            int k = n;
            while (a[j] > a[k])
                k--;
            swap(a[j], a[k]);
            int f = j + 1, l = n;
            while (f < l) {
                swap(a[f], a[l]);
                f++;
                l--;
            }
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}