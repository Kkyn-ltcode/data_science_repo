#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct coordinate {
    int x;
    int y;
    int z;
};

class three_dimentional {
   public:
    int row, col, height;
    coordinate source, destination;
    vector<vector<vector<int>>> step;
    void function();
    void input();
    void solve();
    bool check(int, int, int);
};

bool three_dimentional::check(int x, int y, int z) {
    return (x >= 0 && y >= 0 && z >= 0 && x < row && y < col && z < height);
}

void three_dimentional::solve() {
    queue<coordinate> q;
    q.push(source);
    step[source.x][source.y][source.z] = 0;
    while (!q.empty()) {
        coordinate tmp = q.front();
        q.pop();
        if (check(tmp.x - 1, tmp.y, tmp.z) &&
            step[tmp.x - 1][tmp.y][tmp.z] == -2) {
            step[tmp.x - 1][tmp.y][tmp.z] =
                step[tmp.x][tmp.y][tmp.z] + 1;
            q.push({tmp.x - 1, tmp.y, tmp.z});
        }
        if (check(tmp.x, tmp.y - 1, tmp.z) &&
            step[tmp.x][tmp.y - 1][tmp.z] == -2) {
            step[tmp.x][tmp.y - 1][tmp.z] =
                step[tmp.x][tmp.y][tmp.z] + 1;
            q.push({tmp.x, tmp.y - 1, tmp.z});
        }
        if (check(tmp.x, tmp.y, tmp.z - 1) &&
            step[tmp.x][tmp.y][tmp.z - 1] == -2) {
            step[tmp.x][tmp.y][tmp.z - 1] =
                step[tmp.x][tmp.y][tmp.z] + 1;
            q.push({tmp.x, tmp.y, tmp.z - 1});
        }
        if (check(tmp.x + 1, tmp.y, tmp.z) &&
            step[tmp.x + 1][tmp.y][tmp.z] == -2) {
            step[tmp.x + 1][tmp.y][tmp.z] =
                step[tmp.x][tmp.y][tmp.z] + 1;
            q.push({tmp.x + 1, tmp.y, tmp.z});
        }
        if (check(tmp.x, tmp.y + 1, tmp.z) &&
            step[tmp.x][tmp.y + 1][tmp.z] == -2) {
            step[tmp.x][tmp.y + 1][tmp.z] =
                step[tmp.x][tmp.y][tmp.z] + 1;
            q.push({tmp.x, tmp.y + 1, tmp.z});
        }
        if (check(tmp.x, tmp.y, tmp.z + 1) &&
            step[tmp.x][tmp.y][tmp.z + 1] == -2) {
            step[tmp.x][tmp.y][tmp.z + 1] =
                step[tmp.x][tmp.y][tmp.z] + 1;
            q.push({tmp.x, tmp.y, tmp.z + 1});
        }
    }
    if (step[destination.x][destination.y][destination.z] < 0)
        cout << -1 << endl;
    else
        cout << step[destination.x][destination.y][destination.z] << endl;
}

void three_dimentional::input() {
    cin >> row >> col >> height;
    step.resize(row);
    for (int i = 0; i < row; i++)
        step[i].resize(col, vector<int>(height, -2));
    char tmp;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < height; k++) {
                cin >> tmp;
                if (tmp == '#')
                    step[i][j][k] = -1;
                if (tmp == 'S')
                    source = {i, j, k};
                if (tmp == 'E')
                    destination = {i, j, k};
            }
        }
    }
}

void three_dimentional::function() {
    input();
    solve();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        three_dimentional t;
        t.function();
    }
}