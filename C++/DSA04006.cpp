#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dp(unsigned long int n, unsigned long int l, unsigned long int r) {
    vector<string> b(n + 1, "");
    b[2] = "101";
    b[3] = "111";
    for (unsigned long int i = 4; i <= n; i++) {
        if (i % 2 == 0)
            b[i] = b[i / 2] + "0" + b[i / 2];
        else
            b[i] = b[i / 2] + "1" + b[i / 2];
    }
    unsigned long int count = 0;
    for (unsigned long int i = l; i <= r; i++)
        if (b[n][i] == '1')
            count++;
    cout << count << endl;
}

void drive() {
    unsigned long int n, l, r;
    cin >> n >> l >> r;
    dp(n, l, r);
}

int main() {
    unsigned long int test_case;
    cin >> test_case;
    while (test_case--) {
        drive();
    }
    return 0;
}
