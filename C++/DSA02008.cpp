#include <iostream>
#include <vector>
using namespace std;
int c = 0;
vector<int> final;

void print(vector<int> result, int sum, int n, int k) {
    if (sum != k)
        return;
    c++;
    for (int i = 0; i < n; i++)
        final.push_back(result[i]);
}

void find_number(vector<vector<int>> a, vector<bool>& row,
                 vector<bool>& col, vector<int>& result,
                 int sum, int n, int k, int index) {
    row[index] = true;
    for (int j = 0; j < n; j++) {
        if (!col[j]) {
            col[j] = true;
            sum += a[index][j];
            result[index] = j + 1;
            if (index != n - 1)
                find_number(a, row, col, result, sum, n, k, index + 1);
            else
                print(result, sum, n, k);
            sum -= a[index][j];
            col[j] = false;
        }
    }
    row[index] = false;
}

void drive() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<bool> row(n, false);
    vector<bool> col(n, false);
    vector<int> result(n, 0);
    cout << endl;
    find_number(a, row, col, result, 0, n, k, 0);
    cout << c << endl;
    for (int i = 0; i < final.size(); i++) {
        if ((i + 1) % n == 0)
            cout << final[i] << endl;
        else
            cout << final[i] << " ";
    }
}

int main() {
    drive();
    return 0;
}
