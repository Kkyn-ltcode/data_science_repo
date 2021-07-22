#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<char, int> um = {{'a', 1},
                               {'b', 2},
                               {'c', 3},
                               {'d', 4},
                               {'e', 5},
                               {'f', 6},
                               {'g', 7},
                               {'h', 8}};

struct coordinate {
    int x;
    int y;
};

class knight {
   public:
    coordinate source, destination;
    vector<vector<int>> board;
    vector<vector<bool>> visited;
    vector<coordinate> move = {{-2, 1},
                               {-1, 2},
                               {1, 2},
                               {2, 1},
                               {2, -1},
                               {1, -2},
                               {-1, -2},
                               {-2, -1}};
    void function();
    void input();
    int minimun_step();
};

int knight::minimun_step() {
    queue<coordinate> step;
    step.push(source);
    visited[source.x][source.y] = true;
    if (source.x == destination.x &&
        source.y == destination.y)
        return board[source.x][source.y];
    while (!step.empty()) {
        coordinate tmp = step.front();
        step.pop();
        for (int i = 0; i < 8; i++) {
            coordinate new_step;
            new_step.x = tmp.x + move[i].x;
            new_step.y = tmp.y + move[i].y;
            if (new_step.x >= 0 && new_step.x <= 7 &&
                new_step.y >= 0 && new_step.y <= 7) {
                if (!visited[new_step.x][new_step.y]) {
                    board[new_step.x][new_step.y] = board[tmp.x][tmp.y] + 1;
                    if (new_step.x == destination.x &&
                        new_step.y == destination.y)
                        return board[new_step.x][new_step.y];
                    visited[new_step.x][new_step.y] = true;
                    step.push(new_step);
                }
            }
        }
    }
    return -1;
}

void knight::input() {
    string s, d;
    board.resize(8);
    for (int i = 0; i < 8; i++)
        board[i].resize(8, 0);
    visited.resize(8);
    for (int i = 0; i < 8; i++)
        visited[i].resize(8, false);
    cin >> s >> d;
    source.y = um[s[0]] - 1;
    source.x = s[1] - '0' - 1;
    destination.y = um[d[0]] - 1;
    destination.x = d[1] - '0' - 1;
}

void knight::function() {
    input();
    cout << minimun_step() << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        knight k;
        k.function();
    }
}