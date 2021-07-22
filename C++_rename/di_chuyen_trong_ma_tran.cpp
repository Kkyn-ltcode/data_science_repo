#include <iostream>
using namespace std;
int a[100][100], n, m, c;

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
}

void back_track(int i, int j) {
    if (i == n - 1 && j == m - 1) {
        c++;
        return;
    }
    if (i + 1 < n)
        back_track(i + 1, j);
    if (j + 1 < m)
        back_track(i, j + 1);
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        c = 0;
        init();
        back_track(0, 0);
        cout << c << endl;
    }
    return 0;
}