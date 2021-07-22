#include <iostream>
#include <vector>
using namespace std;

class dp {
   public:
    int a, b;
    vector<vector<int>> x;
    void function();
    void input();
    void find_minimum_number();
    int find_minimum_digit(int, int);
};

int dp::find_minimum_digit(int c, int d) {
    if (c > d || c < 0 || d < 0 || c > 900 || d > 8100)
        return -1;
    if (c == 0 && d == 0)
        return 0;
    if (x[c][d] != -1)
        return x[c][d];
    int res = 101;
    for (int i = 9; i >= 1; i--) {
        int min_digit = find_minimum_digit(c - i, d - i * i);
        if (min_digit != -1)
            res = min(res, min_digit + 1);
    }
    x[c][d] = res;
    return res;
}

void dp::find_minimum_number() {
    int min_digit = find_minimum_digit(a, b);
    if (min_digit == -1 || min_digit > 100)
        cout << -1;
    else {
        while (a > 0 && b > 0) {
            for (int i = 1; i <= 9; i++) {
                if (a >= i && b >= i * i &&
                    1 + x[a - i][b - i * i] == x[a][b]) {
                    a -= i;
                    b -= i * i;
                    cout << i;
                    break;
                }
            }
        }
    }
    cout << endl;
}

void dp::input() {
    cin >> a >> b;
    x.resize(901);
    for (int i = 0; i < 901; i++)
        x[i].resize(8101, -1);
    x[0][0] = 0;
}

void dp::function() {
    input();
    find_minimum_number();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        dp d;
        d.function();
    }
}