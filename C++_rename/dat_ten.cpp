#include <iostream>
#include <vector>
using namespace std;

class solution {
   public:
    int n, k;
    bool end = false;
    vector<int> a;
    vector<char> word = {'A', 'B', 'C', 'D',
                         'E', 'F', 'G', 'H',
                         'I', 'J', 'K', 'L',
                         'M', 'N', 'O', 'P',
                         'Q', 'R', 'S', 'T',
                         'U', 'V', 'W', 'X',
                         'Y', 'Z'};
    void input();
    void function();
    void generate();
    void print();
};

void solution::print() {
    for (int i = 1; i <= k; i++)
        cout << word[a[i] - 1];
    cout << endl;
}

void solution::generate() {
    int i = k;
    while (i >= 0 && a[i] == n - k + i)
        i--;
    if (i > 0) {
        a[i] = a[i] + 1;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[i] + j - i;
    } else
        end = true;
}

void solution::input() {
    cin >> n >> k;
    a.resize(k + 1);
    for (int i = 1; i <= k; i++)
        a[i] = i;
}

void solution::function() {
    input();
    while (!end) {
        print();
        generate();
    }
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        solution s;
        s.function();
    }
}
