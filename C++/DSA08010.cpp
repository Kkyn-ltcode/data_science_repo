#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <math.h>
using namespace std;

struct node {
    int val;
    int level;
};

class op {
   public:
    node num;
    void function();
    void input();
    int minimum_operator();
    set<int> find_max(int);
};

set<int> op::find_max(int n) {
    set<int> res;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            res.insert(max(i, n / i));
    return res;
}

int op::minimum_operator() {
    set<int> visit;
    queue<node> q;
    q.push(num);
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();
        if (tmp.val == 1)
            return tmp.level;
        visit.insert(tmp.val);
        set<int> res = find_max(tmp.val);
        if (tmp.val - 1 == 1)
            return tmp.level + 1;
        set<int>::iterator it = res.begin();
        for (it; it != res.end(); it++)
            if (*it == 1)
                return tmp.level + 1;
        if (visit.find(tmp.val - 1) == visit.end()) {
            node x;
            x.val = tmp.val - 1;
            x.level = tmp.level + 1;
            q.push(x);
        }
        it = res.begin();
        for (it; it != res.end(); it++) {
            if (visit.find(*it) == visit.end()) {
                node x;
                x.val = *it;
                x.level = tmp.level + 1;
                q.push(x);
            }
        }
    }
    return -1;
}

void op::input() {
    cin >> num.val;
    num.level = 0;
}

void op::function() {
    input();
    cout << minimum_operator() << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        op o;
        o.function();
    }
}