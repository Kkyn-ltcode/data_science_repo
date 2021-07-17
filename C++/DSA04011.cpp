#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int make_equal_length(string& x, string& y) {
    int n = x.size();
    int m = y.size();
    if (n < m) {
        for (int i = 0; i < m - n; i++)
            x = '0' + x;
        return m;
    } else if (n > m)
        for (int i = 0; i < n - m; i++)
            y = '0' + y;
    return n;
}

string add(string x, string y) {
    int n = make_equal_length(x, y);
    string res = "";
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        int bit1 = x[i] - '0';
        int bit2 = y[i] - '0';
        int tmp = bit1 ^ bit2 ^ carry;
        res.push_back(tmp + '0');
        carry = (bit1 & bit2) | (bit1 & carry) | (bit2 & carry);
    }
    if (carry == 1)
        res.push_back(carry + '0');
    reverse(res.begin(), res.end());
    return res;
}

int multiply_single(string x, string y) {
    return (x[0] - '0') * (y[0] - '0');
}

long long multiply(string x, string y) {
    int n = make_equal_length(x, y);
    if (n == 1)
        return multiply_single(x, y);
    int l = n / 2;
    int r = n - l;
    string a = x.substr(0, l);
    string b = x.substr(l, r);
    string c = y.substr(0, l);
    string d = y.substr(l, r);
    long long tmp1 = multiply(a, c);
    long long tmp2 = multiply(add(a, b), add(c, d));
    long long tmp3 = multiply(b, d);
    return (tmp1 * (int)pow(2, 2 * r) + (tmp2 - tmp1 - tmp3) * (int)pow(2, r) + tmp3);
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        string x, y;
        cin >> x >> y;
        cout << multiply(x, y) << endl;
    }
    return 0;
}