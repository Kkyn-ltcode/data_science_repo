#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int n, k;
        cin >> n >> k;
        vector<int> comb;
        for (int j = 0; j < k; j++) {
            int d;
            cin >> d;
            comb.push_back(d);
        }
        int i = k - 1;
        while (i >= 0 && comb[i] == n - k + i + 1)
            i--;
        if (comb[0] == n - k + 1) {
            for (int j = 1; j <= k; j++)
                cout << j << " ";
            cout << endl;
            continue;
        }
        if (i >= 0) {
            comb[i] += 1;
            for (int j = i + 1; j < k; j++)
                comb[j] = comb[i] + j - i;
        }
        for (int j = 0; j < k; j++)
            cout << comb[j] << " ";
        cout << endl;
    }
    return 0;
}