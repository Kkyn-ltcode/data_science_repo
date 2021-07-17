#include <iostream>
using namespace std;

void check(int n, int s, int m) {
    if (((n * 6) < (m * 7) && s > 6) || m > n)
        cout << "-1" << endl;
    else {
        int res = (m * s) / n;
        if (((m * s) % n) != 0)
            res++;
        cout << res << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int n, s, m;
        cin >> n >> s >> m;
        check(n, s, m);
    }
    return 0;
}