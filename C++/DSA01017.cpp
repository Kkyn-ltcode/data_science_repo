#include <iostream>
using namespace std;

char convert(char a, char b) {
    return (a == b) ? '0' : '1';
}

void binary_to_gray() {
    string binary;
    cin >> binary;
    string gray = "";
    gray += binary[0];
    for (int i = 1; i < binary.size(); i++)
        gray += convert(binary[i - 1], binary[i]);
    cout << gray << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        binary_to_gray();
    return 0;
}