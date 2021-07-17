#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

struct node {
    int value;
    int frequency;
};

class solution {
   public:
    int n;
    vector<node> a;
    void function();
    void input();
    void find_next_greater_frequency();
};

void solution::find_next_greater_frequency() {
    stack<node> s;
    vector<int> res(n);
    res[n - 1] = -1;
    s.push(a[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        while (!s.empty() && s.top().frequency <= a[i].frequency)
            s.pop();
        res[i] = (s.empty()) ? -1 : s.top().value;
        s.push(a[i]);
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
}

void solution::input() {
    cin >> n;
    vector<int> in(n);
    a.resize(n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        m[in[i]]++;
    }
    for (int i = 0; i < n; i++)
        a[i] = {in[i], m[in[i]]};
}

void solution::function() {
    input();
    find_next_greater_frequency();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        solution s;
        s.function();
    }
}