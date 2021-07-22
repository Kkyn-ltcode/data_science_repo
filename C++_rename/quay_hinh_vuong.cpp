#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct node {
    vector<vector<int>> val;
    int level;
};

class rectangle {
   public:
    vector<vector<int>> rectangle_in;
    vector<vector<int>> rectangle_out;
    void function();
    void input();
    int solve();
    vector<vector<int>> rotate(vector<vector<int>>, int);
};

vector<vector<int>> rectangle::rotate(vector<vector<int>> tmp, int k) {
    swap(tmp[0][k], tmp[0][k + 1]);
    swap(tmp[1][k], tmp[1][k + 1]);
    swap(tmp[0][k], tmp[1][k + 1]);
    return tmp;
}

int rectangle::solve() {
    queue<node> q;
    node tmp;
    tmp.val = rectangle_in;
    tmp.level = 0;
    q.push(tmp);
    set<vector<vector<int>>> visited;
    visited.insert(tmp.val);
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            node x;
            x.val = rotate(tmp.val, i);
            if (x.val == rectangle_out)
                return tmp.level + 1;
            if (visited.find(x.val) == visited.end()) {
                x.level = tmp.level + 1;
                visited.insert(x.val);
                q.push(x);
            }
        }
    }
    return -1;
}

void rectangle::input() {
    rectangle_in.resize(2);
    rectangle_out.resize(2);
    for (int i = 0; i < 2; i++) {
        rectangle_in[i].resize(3);
        rectangle_out[i].resize(3);
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            cin >> rectangle_in[i][j];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            cin >> rectangle_out[i][j];
}

void rectangle::function() {
    input();
    cout << solve() << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        rectangle r;
        r.function();
    }
}