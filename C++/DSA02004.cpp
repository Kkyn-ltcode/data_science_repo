#include <iostream>
#include <vector>
using namespace std;
int a[100][100], n;
vector<char> b;
bool printed;
bool unused[100][100];

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1)
                unused[i][j] = false;
        }
    }
    unused[0][0] = true;
}

void print() {
    for (int i = 0; i < b.size(); i++)
        cout << b[i];
    cout << " ";
    printed = true;
}

void back_track(int d, int r) {
    if (d == n - 1 && r == n - 1) {
        print();
        return;
    }
    if (d < n - 1 && a[d + 1][r] == 1 && !unused[d + 1][r]) {
        b.push_back('D');
        unused[d + 1][r] = true;
        back_track(d + 1, r);
        unused[d + 1][r] = false;
        b.pop_back();
    }
    if (r > 0 && a[d][r - 1] == 1 && !unused[d][r - 1]) {
        b.push_back('L');
        unused[d][r - 1] = true;
        back_track(d, r - 1);
        unused[d][r - 1] = false;
        b.pop_back();
    }
    if (r < n - 1 && a[d][r + 1] == 1 && !unused[d][r + 1]) {
        b.push_back('R');
        unused[d][r + 1] = true;
        back_track(d, r + 1);
        unused[d][r + 1] = false;
        b.pop_back();
    }
    if (d > 0 && a[d - 1][r] == 1 && !unused[d - 1][r]) {
        b.push_back('U');
        unused[d - 1][r] = true;
        back_track(d - 1, r);
        unused[d - 1][r] = false;
        b.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        printed = false;
        if (a[0][0] == 0 || a[n - 1][n - 1] == 0)
            cout << -1;
        else {
            back_track(0, 0);
            if (!printed)
                cout << -1;
        }
        cout << endl;
    }
    return 0;
}
/*
5 
1 0 0 0 0
1 1 1 1 1
0 0 1 0 1
0 1 1 1 1
0 1 1 1 1 
5
1 0 1 1 1
1 1 1 0 1 
0 1 1 0 1
0 1 1 0 1
0 1 1 1 1
*/