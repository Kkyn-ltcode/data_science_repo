#include <iostream>
#include <vector>
using namespace std;
int k;
bool check;

void result(vector<int> a, int n) {
    cout << "(";
    for (int i = 1; i <= k; i++) {
        if (i != k)
            cout << a[i] << " ";
        else
            cout << a[i] << ") ";
    }
}

void Try(vector<int>& a, int n) {
    int i = k, r, s, d;
    while (i > 0 && a[i] == 1)
        i--;
    if (i > 0) {
        a[i] = a[i] - 1;
        d = k - i + 1;
        r = d / a[i];
        s = d % a[i];
        k = i;
        if (r > 0) {
            for (int j = i + 1; j <= i + r; j++)
                a[j] = a[i];
            k = k + r;
        }
        if (s > 0) {
            k += 1;
            a[k] = s;
        }
    } else
        check = false;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int n;
        k = 1;
        check = true;
        cin >> n;
        vector<int> a(n + 1, 0);
        a[k] = n;
        while (check) {
            result(a, n);
            Try(a, n);
        }
        cout << endl;
    }
    return 0;
}