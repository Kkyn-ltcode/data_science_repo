#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class square {
   public:
    long n;
    vector<long> a;
    void function();
    void input();
    long find_max_edge();
    vector<long> find_limit_left();
    vector<long> find_limit_right();
};

vector<long> square::find_limit_right() {
    stack<long> s;
    vector<long> res(n);
    for (long i = n - 1; i >= 0; i--) {
        if (s.empty())
            res[i] = n - 1;
        else {
            if (a[s.top()] < a[i])
                res[i] = s.top() - 1;
            else {
                while (!s.empty() && a[s.top()] >= a[i])
                    s.pop();
                if (s.empty())
                    res[i] = n - 1;
                else
                    res[i] = s.top() - 1;
            }
        }
        s.push(i);
    }
    return res;
}

vector<long> square::find_limit_left() {
    stack<long> s;
    vector<long> res(n);
    for (long i = 0; i < n; i++) {
        if (s.empty())
            res[i] = 0;
        else {
            if (a[s.top()] < a[i])
                res[i] = s.top() + 1;
            else {
                while (!s.empty() && a[s.top()] >= a[i])
                    s.pop();
                if (s.empty())
                    res[i] = 0;
                else
                    res[i] = s.top() + 1;
            }
        }
        s.push(i);
    }
    return res;
}

long square::find_max_edge() {
    vector<long> left = find_limit_left();
    vector<long> right = find_limit_right();
    long max_square_edge = 0;
    for (long i = 0; i < n; i++) {
        long edge;
        edge = ((right[i] - left[i] + 1) >= a[i]) ? min(a[i], right[i] - left[i] + 1) : 0;
        max_square_edge = max(max_square_edge, edge);
    }
    return max_square_edge;
}

void square::input() {
    cin >> n;
    a.resize(n);
    for (long i = 0; i < n; i++)
        cin >> a[i];
}

void square::function() {
    input();
    cout << find_max_edge() << endl;
}

int main() {
    long test_case;
    cin >> test_case;
    while (test_case--) {
        square r;
        r.function();
    }
    return 0;
}