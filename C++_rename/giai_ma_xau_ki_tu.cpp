#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class decryption {
   public:
    string str;
    void function();
    void input();
    void solve();
};

void decryption::solve() {
    stack<char> c;
    stack<int> ratio;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            int count = 0;
            while (str[i] >= '0' && str[i] <= '9') {
                count = count * 10 + str[i] - '0';
                i++;
            }
            i--;
            ratio.push(count);
        } else if (str[i] == ']') {
            int count = 0;
            if (!ratio.empty()) {
                count = ratio.top();
                ratio.pop();
            }
            string tmp = "";
            while (!c.empty() && c.top() != '[') {
                tmp = c.top() + tmp;
                c.pop();
            }
            if (!c.empty() && c.top() == '[')
                c.pop();
            string res = "";
            for (int j = 0; j < count; j++)
                res += tmp;
            for (int j = 0; j < res.size(); j++)
                c.push(res[j]);
        } else if (str[i] == '[') {
            if (str[i - 1] >= '0' && str[i - 1] <= '9')
                c.push(str[i]);
            else {
                ratio.push(1);
                c.push(str[i]);
            }
        } else
            c.push(str[i]);
    }
    string res = "";
    while (!c.empty()) {
        res = c.top() + res;
        c.pop();
    }
    cout << res << endl;
}

void decryption::input() {
    cin >> str;
}

void decryption::function() {
    input();
    solve();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        decryption r;
        r.function();
    }
}