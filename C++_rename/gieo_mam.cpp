#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int timeframe;
    int x;
    int y;
};

class rotten_oranges {
   public:
    vector<vector<int>> a;
    queue<node> q;
    int row, col;
    void function();
    void input();
    int solve();
};

int rotten_oranges::solve() {
    int max_timeframe = 0;
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();
        if ((tmp.x - 1) >= 0) {
            if (a[tmp.x - 1][tmp.y] == 1) {
                q.push({tmp.timeframe + 1, tmp.x - 1, tmp.y});
                a[tmp.x - 1][tmp.y] = 2;
            }
        }
        if ((tmp.x + 1) < row) {
            if (a[tmp.x + 1][tmp.y] == 1) {
                q.push({tmp.timeframe + 1, tmp.x + 1, tmp.y});
                a[tmp.x + 1][tmp.y] = 2;
            }
        }
        if ((tmp.y - 1) >= 0) {
            if (a[tmp.x][tmp.y - 1] == 1) {
                q.push({tmp.timeframe + 1, tmp.x, tmp.y - 1});
                a[tmp.x][tmp.y - 1] = 2;
            }
        }
        if ((tmp.y + 1) < col) {
            if (a[tmp.x][tmp.y + 1] == 1) {
                q.push({tmp.timeframe + 1, tmp.x, tmp.y + 1});
                a[tmp.x][tmp.y + 1] = 2;
            }
        }
        max_timeframe = max(max_timeframe, tmp.timeframe);
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (a[i][j] == 1)
                return -1;
    return max_timeframe;
}

void rotten_oranges::input() {
    cin >> row >> col;
    a.resize(row);
    for (int i = 0; i < row; i++)
        a[i].resize(col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2)
                q.push({0, i, j});
        }
    }
}

void rotten_oranges::function() {
    input();
    cout << solve() << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        rotten_oranges r;
        r.function();
    }
}