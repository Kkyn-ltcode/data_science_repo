#include <iostream>
#include <vector>
using namespace std;

void result(vector<char> a, int n) {
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << " ";
}

void Try(int i, vector<char> a, int n) {
    for (char j = 'A'; j <= 'B'; j++) {
        a[i] = j;
        if (i == n)
            result(a, n);
        else
            Try(i + 1, a, n);
    }
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int n;
        cin >> n;
        vector<char> a(n + 1, 'A');
        Try(1, a, n);
        cout << endl;
    }
    return 0;
}