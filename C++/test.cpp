#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class graph {
   public:
    int vertices, col;
    vector<vector<int>> list;
    vector<bool> visited;
    void function();
    void input();
    int find_num_of_connection();
    void BFS(int);
};

void graph::BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < list[tmp].size(); i++) {
            if (!visited[list[tmp][i]]) {
                visited[list[tmp][i]] = true;
                q.push(list[tmp][i]);
            }
        }
    }
}

int graph::find_num_of_connection() {
    visited.resize(col, false);
    int num_of_connection = 0;
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            num_of_connection++;
            BFS(i);
        }
    }
    return num_of_connection;
}

void graph::input() {
    cin >> vertices >> col;
    list.resize(col);
    char tmp;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < col; j++) {
            cin >> tmp;
            if (tmp == 'W' && i != j)
                list[i].push_back(j);
        }
    }
}

void graph::function() {
    input();
    cout << find_num_of_connection() << endl;
}

int main() {
    graph g;
    g.function();
    return 0;
}