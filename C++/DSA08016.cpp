#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct coordinate {
    int x;
    int y;
};

struct node {
    vector<coordinate> center;
    int level;
};

class hex_game {
   public:
    vector<coordinate> hex_in;
    vector<coordinate> hex_out = {{1, 1}, {1, 2}};
    void function();
    void input();
    int solve();
    vector<coordinate> rolate(vector<coordinate>,
                              map<coordinate, coordinate>);
    bool compare(vector<coordinate>, vector<coordinate>);
    bool compare_coor(coordinate, coordinate);
};

bool hex_game::compare_coor(coordinate a, coordinate b) {
    return ((a.x == b.x) && (a.y == b.y));
}

bool hex_game::compare(vector<coordinate> a, vector<coordinate> b) {
    return (compare_coor(a[0], b[0]) && compare_coor(a[1], b[1]));
}

vector<coordinate> hex_game::rolate(
    vector<coordinate> a, map<coordinate, coordinate> my_map) {
    vector<coordinate> res;
    for (int i = 0; i < 2; i++) {
        coordinate tmp = a[i];
        tmp.x = tmp.x + my_map[a[i]].x;
        tmp.y = tmp.y + my_map[a[i]].y;
        res.push_back(tmp);
    }
    return res;
}

int hex_game::solve() {
    map<coordinate, coordinate>
        my_map1 = {{{0, 0}, {0, 1}},
                   {{0, 1}, {1, 1}},
                   {{1, 2}, {1, -1}},
                   {{2, 1}, {0, -1}},
                   {{2, 0}, {-1, 0}},
                   {{1, 0}, {-1, 0}}};
    map<coordinate, coordinate>
        my_map2 = {{{0, 2}, {1, 1}},
                   {{0, 1}, {0, 1}},
                   {{1, 3}, {1, -1}},
                   {{2, 2}, {0, -1}},
                   {{2, 1}, {-1, 0}},
                   {{1, 1}, {-1, 0}}};
    queue<node> q;
    q.push({hex_in, 0});
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();
        node tmp1;
        tmp1.center = rolate(tmp.center, my_map1);
        if (compare(tmp1.center, hex_out))
            return tmp.level + 1;
        q.push({tmp1.center, tmp.level + 1});
        node tmp2;
        tmp2.center = rolate(tmp.center, my_map2);
        if (compare(tmp2.center, hex_out))
            return tmp.level + 1;
        q.push({tmp2.center, tmp.level + 1});
    }
    return -1;
}

bool operator<(coordinate a, coordinate b) {
    return (make_pair(a.x, a.y) < make_pair(b.x, b.y));
}

void hex_game::input() {
    int tmp;
    for (int i = 0; i < 3; i++) {
        int k = 3;
        if (i == 1)
            k = 4;
        for (int j = 0; j < k; j++) {
            cin >> tmp;
            if (tmp == 0)
                hex_in.push_back({i, j});
        }
    }
}

void hex_game::function() {
    input();
    cout << solve();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        hex_game r;
        r.function();
    }
}