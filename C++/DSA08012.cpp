#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int value;
    int level;
    map<int, bool> m;
};

queue<node> q;
vector<int> ans;

class number {
   public:
    int left, right;
    void function();
    void input();
    void solve();
    void print();
};

void number::print() {
    int count = 0;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] > left && ans[i] < right)
            count++;
        else if (ans[i] == left || ans[i] == right)
            count++;
    }
    cout << count << endl;
}

void number::solve() {
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();
        ans.push_back(tmp.value);
        if (tmp.level == 6)
            continue;
        for (int i = 0; i <= 5; i++) {
            if (!tmp.m[i]) {
                node x;
                x.value = tmp.value * 10 + i;
                x.level = tmp.level + 1;
                x.m = tmp.m;
                x.m[i] = true;
                q.push(x);
            }
        }
    }
}

void number::input() {
    cin >> left >> right;
}

void number::function() {
    input();
    solve();
    print();
}

void generate() {
    q.push({1, 1, {{1, true}}});
    q.push({2, 1, {{2, true}}});
    q.push({3, 1, {{3, true}}});
    q.push({4, 1, {{4, true}}});
    q.push({5, 1, {{5, true}}});
    ans.push_back(0);
}

int main() {
    int test_case;
    cin >> test_case;
    generate();
    while (test_case--) {
        number n;
        n.function();
    }
}