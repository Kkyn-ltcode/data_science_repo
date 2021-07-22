#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class max_combination {
   public:
    int n, sum;
    vector<int> a;
    queue<int> q0;
    queue<int> q1;
    queue<int> q2;
    void function();
    void input();
    void queue_divided();
    int solve();
    vector<int> union_queue();
};

vector<int> max_combination::union_queue() {
    vector<int> res;
    while (!q0.empty()) {
        res.push_back(q0.front());
        q0.pop();
    }
    while (!q1.empty()) {
        res.push_back(q1.front());
        q1.pop();
    }
    while (!q2.empty()) {
        res.push_back(q2.front());
        q2.pop();
    }
    return res;
}

void max_combination::queue_divided() {
    sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        if ((a[i] % 3) == 0)
            q0.push(a[i]);
        else if ((a[i] % 3) == 1)
            q1.push(a[i]);
        else
            q2.push(a[i]);
    }
}

int max_combination::solve() {
    if (sum % 3 == 1) {
        if (!q1.empty())
            q1.pop();
        else {
            if (!q2.empty())
                q2.pop();
            else
                return 0;
            if (!q2.empty())
                q2.pop();
            else
                return 0;
        }
    } else if (sum % 3 == 2) {
        if (!q2.empty())
            q2.pop();
        else {
            if (!q1.empty())
                q1.pop();
            else
                return 0;
            if (!q1.empty())
                q1.pop();
            else
                return 0;
        }
    }
    vector<int> res = union_queue();
    if (res.empty())
        return 0;
    sort(res.begin(), res.end(), greater<int>());
    for (int i = 0; i < res.size(); i++)
        cout << res[i];
    return 1;
}

void max_combination::input() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
}

void max_combination::function() {
    input();
    queue_divided();
    if (solve() == 0)
        cout << -1;
    cout << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        max_combination r;
        r.function();
    }
}