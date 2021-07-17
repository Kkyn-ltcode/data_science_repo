#include <iostream>
#include <vector>
using namespace std;

class solution {
   public:
    int n;
    vector<char> a;
    vector<char> c = {'A', 'H'};
    void input();
    void function();
    void generate(int);
    void solve();
};

void solution::solve() {
    if (a[0] != 'H' || a[n - 1] != 'A')
        return;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'H' && a[i + 1] == 'H')
            return;
    }
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;
}

void solution::generate(int i) {
    for (int j = 0; j < 2; j++) {
        a[i] = c[j];
        if (i == n - 1)
            solve();
        else
            generate(i + 1);
    }
}

void solution::input() {
    cin >> n;
    a.resize(n);
}

void solution::function() {
    input();
    generate(0);
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        solution s;
        s.function();
    }
}
