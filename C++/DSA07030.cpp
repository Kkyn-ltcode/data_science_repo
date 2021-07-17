#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class rectangle {
   public:
    int n, m;
    vector<int> a;
    void function();
    void input();
    int find_max_area();
    vector<int> find_limit_left();
    vector<int> find_limit_right();
};

vector<int> rectangle::find_limit_right() {
    stack<int> s;
    vector<int> res(m);
    for (int i = m - 1; i >= 0; i--) {
        if (s.empty())
            res[i] = m - 1;
        else {
            if (a[s.top()] < a[i])
                res[i] = s.top() - 1;
            else {
                while (!s.empty() && a[s.top()] >= a[i])
                    s.pop();
                if (s.empty())
                    res[i] = m - 1;
                else
                    res[i] = s.top() - 1;
            }
        }
        s.push(i);
    }
    return res;
}

vector<int> rectangle::find_limit_left() {
    stack<int> s;
    vector<int> res(m);
    for (int i = 0; i < m; i++) {
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

int rectangle::find_max_area() {
    vector<int> left = find_limit_left();
    vector<int> right = find_limit_right();
    int max_area = 0;
    for (int i = 0; i < m; i++)
        max_area = max(max_area, (right[i] - left[i] + 1) * a[i]);
    return max_area;
}

void rectangle::input() {
    cin >> n >> m;
    a.resize(m, 0);
    int tmp;
    int max_area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            if (tmp == 0)
                a[j] = 0;
            else
                a[j] += tmp;
        }
        max_area = max(max_area, find_max_area());
    }
    cout << max_area << endl;
}

void rectangle::function() {
    input();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        rectangle r;
        r.function();
    }
    return 0;
}