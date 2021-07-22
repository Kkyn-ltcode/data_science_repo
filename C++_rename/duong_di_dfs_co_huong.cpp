#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class graph {
   public:
    int vertices, edges, start, end;
    vector<vector<int>> list;
    vector<bool> unused;
    vector<int> front;
    void function();
    void input();
    void DFS(int);
    void print_path();
};

void graph::print_path() {
    vector<int> path;
    if (front[end - 1] == -1)
        cout << -1;
    else {
        int tmp = end;
        path.push_back(tmp);
        while (tmp != start) {
            tmp = front[tmp - 1] + 1;
            path.push_back(tmp);
        }
        for (int i = path.size() - 1; i >= 0; i--)
            cout << path[i] << " ";
    }
    cout << endl;
}

void graph::DFS(int v) {
    stack<int> s;
    s.push(v - 1);
    unused[v - 1] = true;
    while (!s.empty()) {
        int tmp = s.top();
        s.pop();
        for (int i = 0; i < list[tmp].size(); i++) {
            if (!unused[list[tmp][i]]) {
                unused[list[tmp][i]] = true;
                front[list[tmp][i]] = tmp;
                s.push(tmp);
                s.push(list[tmp][i]);
                break;
            }
        }
    }
}

void graph::input() {
    cin >> vertices >> edges >> start >> end;
    list.resize(vertices);
    unused.resize(vertices, false);
    front.resize(vertices, -1);
    for (int i = 0; i < edges; i++) {
        int source, destination;
        cin >> source >> destination;
        list[source - 1].push_back(destination - 1);
    }
}

void graph::function() {
    input();
    DFS(start);
    print_path();
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