#include <iostream>
using namespace std;

char flip(char a) {
    return (a == '0') ? '1' : '0';
}

void gray_to_binary() {
    string gray;
    cin >> gray;
    string binary = "";
    binary += gray[0];
    for (int i = 1; i < gray.size(); i++) {
        if (gray[i] == '0')
            binary += binary[i - 1];
        else
            binary += flip(binary[i - 1]);
    }
    cout << binary << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        gray_to_binary();
    return 0;
}