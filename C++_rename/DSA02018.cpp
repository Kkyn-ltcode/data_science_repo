#include <iostream>
#include <vector>
using namespace std;

class math_expression {
   public:
    vector<int> a;
    vector<int> b;
    bool done = false;
    void check();
    int math_calculate(int, int, int);
    void back_track(int);
    void input();
    void function();
};

void math_expression::check() {
    int res = a[0];
    for (int i = 1; i < 5; i++)
        res = math_calculate(res, a[i], b[i]);
    cout << res << endl;
}

int math_expression::math_calculate(int num1, int num2, int index) {
    if (index == 0)
        return num1 + num2;
    if (index == 1)
        return num1 - num2;
    return num1 * num2;
}

void math_expression::back_track(int index) {
    for (int i = 0; i < 3; i++) {
        b[index] = i;
        if (index == 4)
            check();
        else
            back_track(index + 1);
    }
}

void math_expression::input() {
    a.resize(5);
    b.resize(5);
    for (int i = 0; i < 5; i++)
        cin >> a[i];
}

void math_expression::function() {
    input();
    back_track(1);
    if (done)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        math_expression m;
        m.function();
    }
}
