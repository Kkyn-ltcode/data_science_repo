#include <iostream>
#include <queue>
using namespace std;

void greedy() {
    int n;
    cin >> n;
    int i4 = 0, i7 = 0;
    while (n > 0) {
        if (n % 7 == 0) {
            i7++;
            n -= 7;
        } else if (n % 4 == 0) {
            i4++;
            n -= 4;
        } else {
            i4++;
            n -= 4;
        }
    }
    if (n < 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < i4; i++)
        cout << 4;
    for (int i = 0; i < i7; i++)
        cout << 7;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
        greedy();
    return 0;
}