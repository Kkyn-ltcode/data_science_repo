#include <iostream>
#include <vector>
using namespace std;

class graph {
   public:
    int vertices;
    vector<vector<int>> matrix;
    void input();
    void print();
};

void graph::print() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (matrix[i][j])
                cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void graph::input() {
    cin >> vertices;
    matrix.resize(vertices);
    for (int i = 0; i < vertices; i++)
        matrix[i].resize(vertices);
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            cin >> matrix[i][j];
}

int main() {
    graph g;
    g.input();
    g.print();
}