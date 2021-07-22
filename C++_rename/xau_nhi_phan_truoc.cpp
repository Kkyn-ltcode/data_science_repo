#include <iostream>
#include <vector>
using namespace std;

class solution {
   public:
    string a;
    void input();
    void function();
    void generate();
};

void solution::generate() {
    int i = a.size() - 1;
    while (i >= 0 && a[i] != '1')
        i--;
    if (i >= 0)
        a[i] = '0';
    for (int j = i + 1; j < a.size(); j++)
        a[j] = '1';
    cout << a << endl;
}

void solution::input() {
    cin >> a;
}

void solution::function() {
    input();
    generate();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        solution s;
        s.function();
    }
}
