#include <iostream>
#include <vector>
using namespace std;

void dp() {
    int max_weight, n;
    cin >> max_weight >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> x(n + 1, vector<int>(max_weight + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= max_weight; j++) {
            if (j >= a[i] && x[i - 1][j - a[i]] + a[i] > x[i - 1][j])
                x[i][j] = x[i - 1][j - a[i]] + a[i];
            else
                x[i][j] = x[i - 1][j];
        }
    }
    cout << x[n][max_weight] << endl;
}

int main() {
    dp();
    return 0;
}