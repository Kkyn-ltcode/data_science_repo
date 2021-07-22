#include <iostream>
#include <vector>
using namespace std;

void result(vector<int> a, int n) {
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << " ";
}

void Try(int i, vector<int> a, vector<bool>& unused, int n) {
    for (int j = n; j >= 1; j--) {
        if (unused[j]) {
            a[i] = j;
            unused[j] = false;
            if (i == n)
                result(a, n);
            else
                Try(i + 1, a, unused, n);
            unused[j] = true;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int n;
        cin >> n;
        vector<int> a(n + 1, 0);
        vector<bool> unused(n + 1, true);
        Try(1, a, unused, n);
        cout << endl;
    }
    return 0;
}