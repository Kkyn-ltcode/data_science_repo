#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void next_gen(vector<char> &a, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 'A') {
            a[i] = 'B';
            for (int j = i + 1; j < n; j++)
                a[j] = 'A';
            break;
        }
    }
}

void check(vector<char> a, vector<string> &result, int &cnt, int k) {
    int s = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == 'A' && count(a.begin() + i, a.begin() + i + k, 'A') == k)
            s++;
    if (s == 1) {
        cnt++;
        string tmp = "";
        for (int i = 0; i < a.size(); i++)
            tmp += a[i];
        result.push_back(tmp);
    }
}

void print(vector<string> result, int cnt) {
    cout << cnt << endl;
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
}

void drive() {
    int n, k;
    cin >> n >> k;
    vector<char> a(n, 'A');
    vector<string> result;
    int cnt = 0;
    while (count(a.begin(), a.end(), 'B') != n) {
        check(a, result, cnt, k);
        next_gen(a, n);
    }
    print(result, cnt);
}

int main() {
    drive();
    return 0;
}