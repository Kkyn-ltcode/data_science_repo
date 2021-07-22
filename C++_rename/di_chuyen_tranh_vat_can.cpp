#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct coordinate {
    int x;
    int y;
};

class obstacle {
   public:
    int n;
    coordinate source, destination;
    vector<vector<char>> a;
    void function();
    void input();
    void solve();
    bool check(int, int);
};

bool obstacle::check(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n && a[x][y] != 'X');
}

void obstacle::solve() {
    queue<coordinate> q;
    q.push(source);
    vector<vector<int>> step(n, vector<int>(n, -1));
    step[source.x][source.y] = 0;
    while (!q.empty()) {
        coordinate tmp = q.front();
        q.pop();
        for (int i = tmp.x - 1; i >= 0; i--) {
            if (check(i, tmp.y) && step[i][tmp.y] == -1) {
                step[i][tmp.y] = step[tmp.x][tmp.y] + 1;
                q.push({i, tmp.y});
            } else
                break;
        }
        for (int i = tmp.x + 1; i < n; i++) {
            if (check(i, tmp.y) && step[i][tmp.y] == -1) {
                step[i][tmp.y] = step[tmp.x][tmp.y] + 1;
                q.push({i, tmp.y});
            } else
                break;
        }
        for (int i = tmp.y - 1; i >= 0; i--) {
            if (check(tmp.x, i) && step[tmp.x][i] == -1) {
                step[tmp.x][i] = step[tmp.x][tmp.y] + 1;
                q.push({tmp.x, i});
            } else
                break;
        }
        for (int i = tmp.y + 1; i < n; i++) {
            if (check(tmp.x, i) && step[tmp.x][i] == -1) {
                step[tmp.x][i] = step[tmp.x][tmp.y] + 1;
                q.push({tmp.x, i});
            } else
                break;
        }
    }
    cout << step[destination.x][destination.y] << endl;
}

void obstacle::input() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        a[i].resize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    cin >> source.x >> source.y >> destination.x >> destination.y;
}

void obstacle::function() {
    input();
    solve();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        obstacle r;
        r.function();
    }
}