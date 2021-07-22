#include <iostream>
#include <string>
using namespace std;

string convert(string& a, string before, string after) {
    while (a.find(before) != -1)
        a.replace(a.find(before), 1, after);
    return a;
}

void add(string a, string b) {
    int x = 0, y = 0;
    for (int i = 0; i < a.size(); i++)
        x = x * 10 + a[i] - '0';
    for (int i = 0; i < b.size(); i++)
        y = y * 10 + b[i] - '0';
    cout << x + y << " ";
    return;
}

void min(string a, string b) {
    a = convert(a, "6", "5");
    b = convert(b, "6", "5");
    add(a, b);
    return;
}

void max(string a, string b) {
    a = convert(a, "5", "6");
    b = convert(b, "5", "6");
    add(a, b);
    return;
}

int main() {
    string a, b;
    cin >> a >> b;
    min(a, b);
    max(a, b);
    return 0;
}