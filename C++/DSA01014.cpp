#include <iostream>
#include <vector>
using namespace std;

class solution {
   public:
    int n, k, s;
    bool end = false;
    vector<int> a;
    int res;
    void input();
    void function(int, int, int);
    void generate();
    void check();
};

void solution::check() {
    int sum = 0;
    for (int i = 1; i <= k; i++)
        sum += a[i];
    if (sum == s)
        res++;
}

void solution::generate() {
    int i = k;
    while (i >= 0 && a[i] == n - k + i)
        i--;
    if (i > 0) {
        a[i] = a[i] + 1;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[i] + j - i;
    } else
        end = true;
}

void solution::input() {
    res = 0;
    a.resize(k + 1);
    for (int i = 1; i <= k; i++)
        a[i] = i;
}

void solution::function(int tmp1, int tmp2, int tmp3) {
    n = tmp1;
    k = tmp2;
    s = tmp3;
    if (n < k) {
        cout << 0 << endl;
        return;
    }
    input();
    while (!end) {
        check();
        generate();
    }
    cout << res << endl;
}

int main() {
    int tmp1, tmp2, tmp3;
    cin >> tmp1 >> tmp2 >> tmp3;
    while (tmp1 != 0 || tmp2 != 0 || tmp3 != 0) {
        solution s;
        s.function(tmp1, tmp2, tmp3);
        cin >> tmp1 >> tmp2 >> tmp3;
    }
}
