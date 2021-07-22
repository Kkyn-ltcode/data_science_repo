#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class rectangle {
   public:
    long long n;
    vector<long long> a;
    void function();
    void input();
    long long find_max_area();
    vector<long long> find_limit_left();
    vector<long long> find_limit_right();
};

vector<long long> rectangle::find_limit_right() {
    stack<long long> s;
    vector<long long> res(n);
    for (long long i = n - 1; i >= 0; i--) {
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

vector<long long> rectangle::find_limit_left() {
    stack<long long> s;
    vector<long long> res(n);
    for (long long i = 0; i < n; i++) {
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

long long rectangle::find_max_area() {
    vector<long long> left = find_limit_left();
    vector<long long> right = find_limit_right();
    vector<long long> area(n);
    long long max_area = 0;
    for (long long i = 0; i < n; i++)
        max_area = max(max_area, (right[i] - left[i] + 1) * a[i]);
    return max_area;
}

void rectangle::input() {
    cin >> n;
    a.resize(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
}

void rectangle::function() {
    input();
    cout << find_max_area() << endl;
}

int main() {
    long long test_case;
    cin >> test_case;
    while (test_case--) {
        rectangle r;
        r.function();
    }
    return 0;
}