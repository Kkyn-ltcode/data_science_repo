#include <iostream>
#include <vector>
using namespace std;

void multiplication_expression() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    vector<int> b(m, 0);
    vector<int> c(n + m - 1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            c[i + j] += a[i] * b[j];
    for (int i = 0; i < m + n - 1; i++)
        cout << c[i] << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        multiplication_expression();
    }
    return 0;
}