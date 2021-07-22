#include <algorithm>
#include <iostream>
using namespace std;
int a[100], n, k, s = 0, b[100];
bool printed;

void init() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
}

void print() {
    int m;
    for (int i = 0; i < n; i++)
        if (b[i] == 1)
            m = i;
    cout << "[";
    for (int j = 0; j < n; j++) {
        if (b[j] == 1) {
            cout << a[j];
            if (j != m)
                cout << " ";
        }
    }
    cout << "] ";
}

void sum() {
    for (int i = 0; i < n; i++)
        s += a[i] * b[i];
    if (s == k) {
        printed = true;
        print();
    }
    s = 0;
}

void back_track(int i) {
    for (int j = 1; j >= 0; j--) {
        b[i] = j;
        if (i == n - 1)
            sum();
        else
            back_track(i + 1);
    }
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        printed = false;
        init();
        back_track(0);
        if (!printed)
            cout << "-1";
        cout << endl;
    }
    return 0;
}