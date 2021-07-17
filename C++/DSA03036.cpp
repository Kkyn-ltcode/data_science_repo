#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class solution {
   public:
    int n;
    vector<int> a;
    void function();
    void input();
    void print();
};

void solution::print() {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i = 1; i < n; i++)
        cout << a[i] << " ";
    if (a[n - 1] == 1)
        cout << 0 << endl;
    else
        cout << 1 << endl;
}

void solution::input() {
    cin >> n;
    a.resize(n, 0);
    for (int i = 0; i < n; i++)
        if (i % 2 != 0)
            a[i] = 1;
}

void solution::function() {
    input();
    print();
}

int main() {
    solution s;
    s.function();
}