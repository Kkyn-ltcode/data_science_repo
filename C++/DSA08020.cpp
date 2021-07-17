#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct node {
    int val;
    int level;
    vector<int> c;
};

class prime_transform {
   public:
    int source, destination;
    void function();
    node input();
    int solve(node);
    int form_num(vector<int>);
    bool is_prime(int);
};

bool prime_transform::is_prime(int n) {
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int prime_transform::form_num(vector<int> a) {
    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res = res * 10 + a[i];
    return res;
}

int prime_transform::solve(node x) {
    queue<node> q;
    q.push(x);
    set<int> visited;
    visited.insert(source);
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();
        if (tmp.val == destination)
            return tmp.level;
        for (int i = 0; i < 4; i++) {
            int j = 0;
            if (i == 0)
                j = 1;
            for (j; j < 10; j++) {
                node y;
                y.c = tmp.c;
                y.c[i] = j;
                y.val = form_num(y.c);
                if (y.val == destination)
                    return tmp.level + 1;
                if (is_prime(y.val)) {
                    if (visited.find(y.val) == visited.end()) {
                        y.level = tmp.level + 1;
                        visited.insert(y.val);
                        q.push(y);
                    }
                }
            }
        }
    }
    return -1;
}

node prime_transform::input() {
    cin >> source >> destination;
    node tmp;
    tmp.val = source;
    tmp.level = 0;
    tmp.c.resize(4);
    int x = source;
    int index = 3;
    while (x) {
        tmp.c[index--] = x % 10;
        x /= 10;
    }
    return tmp;
}

void prime_transform::function() {
    node tmp = input();
    cout << solve(tmp) << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        prime_transform r;
        r.function();
    }
}