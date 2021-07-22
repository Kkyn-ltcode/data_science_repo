#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> a, int n) {
    vector<int> b = a;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        if (!(b[i] == a[i]) && !(b[i] == a[n - i - 1]))
            return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int m = 0; m < t; m++) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            a.push_back(v);
        }
        if (check(a, n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}