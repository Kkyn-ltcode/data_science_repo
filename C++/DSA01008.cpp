#include <iostream>
#include <vector>
using namespace std;

void result(vector<int> a, int n, int k) {
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == 1)
            count++;
    if (count != k)
        return;
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << endl;
}

void Try(int i, vector<int> a, int n, int k) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n)
            result(a, n, k);
        else
            Try(i + 1, a, n, k);
    }
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1, 0);
        Try(1, a, n, k);
    }
    return 0;
}