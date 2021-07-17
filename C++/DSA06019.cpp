#include <iostream>
#include <vector>
using namespace std;

void greedy() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        greedy();
    }
    return 0;
}