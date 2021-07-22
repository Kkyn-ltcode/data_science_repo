#include <iostream>
#include <vector>
using namespace std;
int max_total = 0;

bool is_safe(int row, int col, vector<bool> slash,
             vector<bool> back_slash, vector<bool> row_check,
             vector<vector<bool>> is_valid, int n) {
    if (slash[row + col] || back_slash[row - col + n - 1] || row_check[row] || is_valid[row][col])
        return false;
    return true;
}

void queens_solution(vector<vector<int>> board, int col,
                     vector<bool>& slash, vector<bool>& back_slash,
                     vector<bool>& row_check, vector<vector<bool>>& is_valid,
                     int total, int n) {
    for (int row = 0; row < n; row++) {
        if (is_safe(row, col, slash, back_slash,
                    row_check, is_valid, n)) {
            is_valid[row][col] = true;
            row_check[row] = true;
            slash[row + col] = true;
            back_slash[row - col + n - 1] = true;
            total += board[row][col];
            if (col == n - 1) {
                if (total > max_total) {
                    max_total = total;
                }
            } else
                queens_solution(board, col + 1, slash, back_slash,
                                row_check, is_valid, total, n);
            is_valid[row][col] = false;
            row_check[row] = false;
            slash[row + col] = false;
            back_slash[row - col + n - 1] = false;
            total -= board[row][col];
        }
    }
}

void solve_queen() {
    int n = 8;
    max_total = 0;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<bool>> is_valid(n, vector<bool>(n, false));
    vector<bool> slash(2 * n - 1, false);
    vector<bool> back_slash(2 * n - 1, false);
    vector<bool> row_check(n, false);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    queens_solution(board, 0, slash, back_slash,
                    row_check, is_valid, 0, n);
    cout << max_total << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        solve_queen();
    }
    return 0;
}