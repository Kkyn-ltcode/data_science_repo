#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct edge {
    int source;
    int destination;
};

class graph {
   public:
    int vertices, edges, u;
    vector<vector<int>> list;
    vector<bool> visited;
    vector<edge> res;
    void function();
    void input();
    void DFS();
    void print();
};

void graph::print() {
    if (res.size() == vertices - 1) {
        for (int i = 0; i < res.size(); i++)
            cout << res[i].source + 1 << " " << res[i].destination + 1 << endl;
    } else
        cout << -1 << endl;
}

void graph::DFS() {
    stack<int> s;
    s.push(u - 1);
    visited[u - 1] = true;
    while (!s.empty()) {
        int tmp = s.top();
        s.pop();
        for (int i = 0; i < list[tmp].size(); i++) {
            if (!visited[list[tmp][i]]) {
                visited[list[tmp][i]] = true;
                edge e = {tmp, list[tmp][i]};
                res.push_back(e);
                s.push(tmp);
                s.push(list[tmp][i]);
                break;
            }
        }
    }
}

void graph::input() {
    cin >> vertices >> edges >> u;
    list.resize(vertices);
    visited.resize(vertices, false);
    for (int i = 0; i < edges; i++) {
        int start, end;
        cin >> start >> end;
        list[start - 1].push_back(end - 1);
        list[end - 1].push_back(start - 1);
    }
}

void graph::function() {
    input();
    DFS();
    print();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        graph g;
        g.function();
    }
    return 0;
}