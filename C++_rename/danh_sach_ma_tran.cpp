#include <iostream>
#include <vector>
using namespace std;

class graph {
   public:
    int vertices;
    vector<vector<int>> matrix;
    void input();
    void print();
    void add(string, int);
};

void graph::add(string s, int index) {
    for (int i = 0; i < s.size(); i++) {
        int tmp = 0;
        while (isdigit(s[i])) {
            tmp = tmp * 10 + s[i] - '0';
            i += 1;
        }
        if (tmp < vertices && tmp > 0) {
            matrix[index][tmp - 1] = 1;
            matrix[tmp - 1][index] = 1;
        }
    }
}

void graph::print() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
void graph::input() {
    cin >> vertices;
    cin.ignore();
    matrix.resize(vertices);
    for (int i = 0; i < vertices; i++)
        matrix[i].resize(vertices, 0);
    for (int i = 0; i < vertices; i++) {
        string s = "";
        while (s == "")
            getline(cin, s);
        add(s, i);
    }
}

int main() {
    graph g;
    g.input();
    g.print();
}